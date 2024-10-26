/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Wilkins Cedano                              */
/*  Matricula: 99-0544                                     */
/*  Seccion:   Miercoles                                   */
/*  Practica:  SQLite                                     */
/*  Fecha:     9/10/2024                                   */
/***********************************************************/

#include <stdio.h>
#include "crud.h"

// Callback function to print rows
int print_row(void *NotUsed, int argc, char **argv, char **colName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", colName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    char name[20];
    int edad = 0;
    float salario = 0.0;
    CRUD crud;
    const char *db_name = "test.db";

    if (crud_open(&crud, db_name)) return 1;

    // Create table
    const char *create_sql = "CREATE TABLE IF NOT EXISTS Users (id INTEGER PRIMARY KEY, name TEXT, age INTEGER, salary REAL);";
    crud_create_table(&crud, create_sql);

    // Insert data with int and float
    printf("inserto los datos de la parsona\r\n");
    scanf("%s",name);
    scanf("%d", &edad);
    scanf("%f", &salario);
    const char *insert_sql = "INSERT INTO Users (name, age, salary) VALUES (?, ?, ?);";
    crud_insert(&crud, insert_sql, name, edad, salario);

    // Read data
    const char *select_sql = "SELECT * FROM Users;";
    crud_read(&crud, select_sql, print_row);

    // Update data with int and float
    const char *update_sql = "UPDATE Users SET name = ?, age = ?, salary = ? WHERE id = 1;";
    crud_update(&crud, update_sql, "Alice Smith", 31, 60000.0);

    // Delete data using an int
    const char *delete_sql = "DELETE FROM Users WHERE id = ?;";
    crud_delete(&crud, delete_sql, 1);

    crud_close(&crud);
    return 0;
}
