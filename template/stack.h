#ifndef _TEMPLATE_STACK_INCLUDED_H_
#define _TEMPLATE_STACK_INCLUDED_H_

#include "stack_internal.h"

#define new_stack(name, type) _new_stack_internal(name, type)

struct _stack {
	void *base_ptr, *top_ptr;
	void (*push)(const void *val);
	void (*traverse)(void);
	int (*length)(void);
	void *(*pop)(void);
	void (*pop_all)(void);
	void *next;
};

typedef struct _stack stack_t;

void delete_stack(stack_t **stack);

#endif // _TEMPLATE_LIST_INCLUDED_H_
