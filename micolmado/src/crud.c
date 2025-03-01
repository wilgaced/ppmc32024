
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
#include "crud.h"

// Function to open the database
int crud_open(CRUD *crud, const char *db_name) {
    if (sqlite3_open(db_name, &crud->db) != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(crud->db));
        return 1;
    }
    return 0;
}

// Function to close the database
int crud_close(CRUD *crud) {
    if (sqlite3_close(crud->db) != SQLITE_OK) {
        fprintf(stderr, "Can't close database: %s\n", sqlite3_errmsg(crud->db));
        return 1;
    }
    return 0;
}

// Function to create a table
int crud_create_table(CRUD *crud, const char *sql) {
    char *err_msg = NULL;
    if (sqlite3_exec(crud->db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        return 1;
    }
    return 0;
}

// Function to insert data with int and float values
int crud_insert(CRUD *crud, const char *sql, const char *text, int int_data, float float_data) {
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(crud->db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(crud->db));
        return 1;
    }

    sqlite3_bind_text(stmt, 1, text, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, int_data);
    sqlite3_bind_double(stmt, 3, float_data);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fprintf(stderr, "Execution failed: %s\n", sqlite3_errmsg(crud->db));
        sqlite3_finalize(stmt);
        return 1;
    }
    
    sqlite3_finalize(stmt);
    return 0;
}

// Function to read data
int crud_read(CRUD *crud, const char *sql, int (*callback)(void *, int, char **, char **), void *data) {
    char *err_msg = NULL;
    if (sqlite3_exec(crud->db, sql, callback, data, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        return 1;
    }
    return 0;
}

// Function to update data with int and float values
int crud_update(CRUD *crud, const char *sql, const char *text, int int_data, float float_data) {
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(crud->db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(crud->db));
        return 1;
    }

    sqlite3_bind_text(stmt, 1, text, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, int_data);
    sqlite3_bind_double(stmt, 3, float_data);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fprintf(stderr, "Execution failed: %s\n", sqlite3_errmsg(crud->db));
        sqlite3_finalize(stmt);
        return 1;
    }

    sqlite3_finalize(stmt);
    return 0;
}

// Function to delete data using an int value
int crud_delete(CRUD *crud, const char *sql, int int_data) {
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(crud->db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(crud->db));
        return 1;
    }

    sqlite3_bind_int(stmt, 1, int_data);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fprintf(stderr, "Execution failed: %s\n", sqlite3_errmsg(crud->db));
        sqlite3_finalize(stmt);
        return 1;
    }

    sqlite3_finalize(stmt);
    return 0;
}
