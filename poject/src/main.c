
/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Wilkins Cedano                              */
/*  Matricula: 99-0544                                     */
/*  Seccion:   Miercoles                                   */
/*  Practica:  SQLite                                     */
/*  Fecha:     9/10/2024                                   */
/***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Function prototypes
void createTable(sqlite3 *db);
void insertStudent(sqlite3 *db, int id, const char *name, int age, const char *major);
void displayStudents(sqlite3 *db);
void updateStudent(sqlite3 *db, int id, const char *name, int age, const char *major);
void deleteStudent(sqlite3 *db, int id);
void closeDatabase(sqlite3 *db);

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("student.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    } else {
        printf("Opened database successfully.\n");
    }

    createTable(db);
    insertStudent(db, 1, "Alice", 20, "Computer Science");
    insertStudent(db, 2, "Bob", 22, "Mathematics");
    insertStudent(db, 3, "Charlie", 21, "Physics");
    
    printf("\nDisplaying Students:\n");
    displayStudents(db);
    
    printf("\nUpdating Student with ID 2:\n");
    updateStudent(db, 2, "Bob Updated", 23, "Statistics");
    displayStudents(db);

    printf("\nDeleting Student with ID 1:\n");
    deleteStudent(db, 1);
    displayStudents(db);

    closeDatabase(db);
    return 0;
}

// Function to create the student table
void createTable(sqlite3 *db) {
    char *errMsg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS Students("
                      "ID INT PRIMARY KEY NOT NULL,"
                      "Name TEXT NOT NULL,"
                      "Age INT NOT NULL,"
                      "Major TEXT NOT NULL);";
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Table created successfully.\n");
    }
}

// Function to insert a student record
void insertStudent(sqlite3 *db, int id, const char *name, int age, const char *major) {
    char *errMsg = 0;
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO Students (ID, Name, Age, Major) VALUES (%d, '%s', %d, '%s');", id, name, age, major);

    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Record inserted successfully.\n");
    }
}

// Function to display all students
void displayStudents(sqlite3 *db) {
    const char *sql = "SELECT * FROM Students;";
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *name = sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        const unsigned char *major = sqlite3_column_text(stmt, 3);

        printf("ID: %d, Name: %s, Age: %d, Major: %s\n", id, name, age, major);
    }

    sqlite3_finalize(stmt);
}

// Function to update a student's information
void updateStudent(sqlite3 *db, int id, const char *name, int age, const char *major) {
    char *errMsg = 0;
    char sql[256];
    snprintf(sql, sizeof(sql), "UPDATE Students SET Name = '%s', Age = %d, Major = '%s' WHERE ID = %d;", name, age, major, id);

    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Record updated successfully.\n");
    }
}

// Function to delete a student record
void deleteStudent(sqlite3 *db, int id) {
    char *errMsg = 0;
    char sql[128];
    snprintf(sql, sizeof(sql), "DELETE FROM Students WHERE ID = %d;", id);

    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Record deleted successfully.\n");
    }
}

// Function to close the database connection
void closeDatabase(sqlite3 *db) {
    sqlite3_close(db);
    printf("Database closed successfully.\n");
}
