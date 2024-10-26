#ifndef CRUD_H
#define CRUD_H

#include <sqlite3.h>

// Define a struct for CRUD operations
typedef struct {
    sqlite3 *db;
} CRUD;

// Function declarations
int crud_open(CRUD *crud, const char *db_name);
int crud_close(CRUD *crud);

int crud_create_table(CRUD *crud, const char *sql);
int crud_insert(CRUD *crud, const char *sql, const char *text, int int_data, float float_data);
int crud_read(CRUD *crud, const char *sql, int (*callback)(void *, int, char **, char **));
int crud_update(CRUD *crud, const char *sql, const char *text, int int_data, float float_data);
int crud_delete(CRUD *crud, const char *sql, int int_data);

#endif // CRUD_H
