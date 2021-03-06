#ifndef _TEMPLATE_LIST_INCLUDED_H_
#define _TEMPLATE_LIST_INCLUDED_H_

#include "list_internal.h"

#define new_list(name, type) _new_list_internal(name, type)

typedef struct _list list_t;

struct _list {
	void *curr_ptr, *end_ptr;
	void (*insert)(/* type val */);
	void (*for_each)(void (*callback)(/* type val, int index, list_t **list */));
	int (*length)(void);
	void (*remove)(/* type val */);
	void *(*remove_last)(void);
	void (*remove_all)(void);
	void *start;
};

void delete_list(list_t **list);

#endif // _TEMPLATE_LIST_INCLUDED_H_
