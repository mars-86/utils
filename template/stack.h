#ifndef _TEMPLATE_STACK_INCLUDED_H_
#define _TEMPLATE_STACK_INCLUDED_H_

#include "stack_internal.h"

#define new_stack(name, type) _new_stack_internal(name, type)

typedef struct _stack stack_t;

struct _stack {
	void *top_ptr;
	void (*push)(/* type val */);
	void (*for_each)(void (*callback)(/* type val, int index, stack_t **stack */));
	int (*length)(void);
	void *(*pop)(void);
	void (*pop_all)(void);
	void *start;
};

void delete_stack(stack_t **stack);

#endif // _TEMPLATE_LIST_INCLUDED_H_
