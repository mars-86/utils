#ifndef _TEMPLATE_STACK_INTERNAL_INCLUDED_H_
#define _TEMPLATE_STACK_INTERNAL_INCLUDED_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define _new_stack_internal(name, type) \
	struct _##name##node { \
		type d;	\
		struct _##name##node *prev;	\
		struct _##name##node *next;	\
	}; \
	void name##_push(type val) \
	{ \
		struct _##name##node *_##name##node_temp, *_##name##node_last; \
		if ((name)->start == NULL) {	\
			_create_node_internal(struct _##name##node, _##name##node_temp, val, NULL); \
            name->start = name->top_ptr = (struct _##name##node *)_##name##node_temp; \
			return; \
		} \
		_##name##node_last = (struct _##name##node *)name->top_ptr; \
		_create_node_internal(struct _##name##node, _##name##node_temp, val, _##name##node_last); \
		name->top_ptr = _##name##node_last->next = (struct _##name##node *)_##name##node_temp; \
	} \
	void name##_for_each(void (*callback)(type elem, int index, stack_t **stack)) \
	{ \
        _template_for_each_internal(_##name##node, name, callback); \
	} \
	int name##_length(void) \
	{ \
        struct _##name##node *_##name##node_temp = (struct _##name##node *)name->start; \
        int i = 0; \
        while (_##name##node_temp != NULL) \
            ++i, _##name##node_temp =_##name##node_temp->next; \
        return i; \
	} \
	void *name##_pop(void) \
	{ \
        if(name->top_ptr == NULL) return NULL; \
		struct _##name##node *_##name##node_temp, *_##name##node_last; \
		_##name##node_temp = (struct _##name##node *)name->top_ptr; \
		if(_##name##node_temp->prev != NULL) { \
            name->top_ptr = _##name##node_last = _##name##node_temp->prev; \
            _##name##node_last->next = NULL; \
		} \
        else \
            name->start = name->top_ptr = NULL; \
		_delete_node_internal(_##name##node_temp); \
		return NULL; \
	} \
	void name##_pop_all(void) \
	{ \
        if(name->top_ptr == NULL) return; \
        struct _##name##node *_##name##node_temp = (struct _##name##node *)name->top_ptr; \
        while(_##name##node_temp != NULL) { \
            name->top_ptr = _##name##node_temp->prev; \
            _delete_node_internal(_##name##node_temp); \
            _##name##node_temp = (struct _##name##node *)name->top_ptr; \
        } \
        name->start = name->top_ptr = NULL; \
	} \
    void name##_create_stack(stack_t **stack) { \
		*stack = (stack_t *)malloc(sizeof(stack_t)); \
		(*stack)->start = (*stack)->top_ptr = NULL; \
		(*stack)->push = &name##_push; \
		(*stack)->for_each = &name##_for_each; \
		(*stack)->length = &name##_length; \
		(*stack)->pop = &name##_pop; \
		(*stack)->pop_all = &name##_pop_all; \
	} \
	name##_create_stack(&name);

#endif // _TEMPLATE_STACK_INTERNAL_INCLUDED_H_
