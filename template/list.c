#include "list.h"

void delete_list(list_t **list)
{
    (*list)->remove_all();
    free(*list);
}
