#ifndef _VIEW_TABLE_INCLUDED_H_
#define _VIEW_TABLE_INCLUDED_H_

#include "../template/list.h"

typedef struct _table_row row_t;

struct _table {
    int rows;
    int cols;
    row_t *start, *last_row;
};

typedef struct _table table_t;

struct _table_row {
    list_t *row;
    struct _table_row *next;
};

struct _table_config {
    unsigned col_width;
    unsigned row_heigth;
    char data_type[10];
};

typedef struct _table_config table_config_t;

int table_create(table_t **table, const char **headers, table_config_t *config);
void table_print(table_t *table);
void table_cleanup(table_t **table);

#endif // _VIEW_TABLE_INCLUDED_H_
