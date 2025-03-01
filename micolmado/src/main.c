#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crud.h"
#include <sqlite3.h>

#define DB_NAME "login.db"

typedef struct {
    CRUD crud;
} App;

// Callback para verificar si hay usuarios en la base de datos
static int user_count_callback(void *data, int argc, char **argv, char **col_name) {
    int *count = (int *)data;
    *count = atoi(argv[0]);
    return 0;
}

// Función para verificar si la base de datos está vacía
int is_database_empty(App *app) {
    int count = 0;
    const char *sql = "SELECT COUNT(*) FROM users";
    crud_read(&app->crud, sql, user_count_callback, &count);
    return count == 0;
}

// Función para agregar un usuario
void add_user(App *app, const char *username, const char *password, const char *role) {
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO users (username, password, role) VALUES ('%s', '%s', '%s');", username, password, role);
    crud_insert(&app->crud, sql, NULL, 0, 0.0);
    printf("Usuario %s agregado con rol %s.\n", username, role);
}

// Callback para verificar si el usuario y contraseña existen
static int login_callback(void *data, int argc, char **argv, char **col_name) {
    int *valid = (int *)data;
    *valid = 1;  // Si la consulta devuelve resultados, el usuario existe
    return 0;
}

// Función de inicio de sesión con la versión modificada de crud_read
int login(App *app, const char *username, const char *password) {
    char sql[256];
    snprintf(sql, sizeof(sql), 
             "SELECT role FROM users WHERE username = '%s' AND password = '%s';", 
             username, password);
    int valid = 0;  // Inicialmente, asumimos que no es válido
    crud_read(&app->crud, sql, login_callback, &valid); // Ahora pasa el puntero &valid
    return valid;
}

int main() {
    App app;
    if (crud_open(&app.crud, DB_NAME) != 0) {
        return 1;
    }

    // Crear la tabla si no existe
    const char *sql_create_table =
        "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT UNIQUE, password TEXT, role TEXT);";
    crud_create_table(&app.crud, sql_create_table);

    // Verificar si la base de datos está vacía
    if (is_database_empty(&app)) {
        char username[50], password[50];
        printf("No hay usuarios en la base de datos.\nIngrese el primer usuario: ");
        scanf("%s", username);
        printf("Ingrese la contraseña: ");
        scanf("%s", password);
        add_user(&app, username, password, "admin");
    }

    // Proceso de inicio de sesión
    char username[50], password[50];
    printf("\nInicio de sesión\nUsuario: ");
    scanf("%s", username);
    printf("Contraseña: ");
    scanf("%s", password);
    
    if (login(&app, username, password)) {
        printf("Acceso concedido. Bienvenido %s!\n", username);
    } else {
        printf("Acceso denegado. Usuario o contraseña incorrectos.\n");
    }

    crud_close(&app.crud);
    return 0;
}
