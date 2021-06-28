#include "table.h"

row_t *create_row(list_t *row)
{
    row_t *new_row = (row_t *)malloc(sizeof(row_t));
    new_row->row = row;
    new_row->next = NULL;
    return new_row;
}

void print_row(char *elem)
{
    printf("%s\t", elem);
}

void table_insert_row(table_t **table, list_t *row)
{
    row_t *new_row = create_row(row);
    new_row->row->for_each(print_row);
    if ((*table)->start == NULL) {
        printf("TABLE->START == NULL\n");
        (*table)->start = (*table)->last_row = new_row;
        return;
    }
    printf("TABLE->START != NULL\n");
    (*table)->last_row->next = new_row;
    (*table)->last_row = new_row;
}

int table_create(table_t **table, const char **headers, table_config_t *config)
{
    list_t *head;
    new_list(head, char *);
    *table = (table_t *)malloc(sizeof(table_t));
    (*table)->start = (*table)->last_row = NULL;

    int i, j;
    for (i = 0; i < 3; ++i)
        head->insert(headers[i]);
    table_insert_row(table, head);

    return 0;
}

void table_print(table_t *table)
{
    row_t *row_ptr;
    for (row_ptr = table->start; row_ptr != NULL; row_ptr = row_ptr->next)
        (*row_ptr).row->for_each(print_row);
}

void table_cleanup(table_t **table)
{
    printf("ACA");
    row_t *row_ptr;
    for (row_ptr = (*table)->start; row_ptr != NULL; row_ptr = row_ptr->next) {
        row_t *row_ptr_tmp = row_ptr;
        delete_list(&(row_ptr_tmp->row));
        row_ptr_tmp->row = NULL;
    }
    printf("ACA");
    free(*table);
}
