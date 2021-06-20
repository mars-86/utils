#ifndef _TEMPLATE_LIST_INCLUDED_H_
#define _TEMPLATE_LIST_INCLUDED_H_

#include "list_internal.h"

#define new_list(name, type) _new_list_internal(name, type)

struct _list {
	void *begin_ptr, *curr_ptr, *end_ptr;
	void (*insert)(const void *(n));
	void (*traverse)(void);
	int (*length)(void);
	void (*remove)(const void *);
	void *(*remove_last)(void);
	void (*remove_all)(void);
	void *next;
};

typedef struct _list list_t;

void delete_list(list_t **list);

#endif // _TEMPLATE_LIST_INCLUDED_H_
