#ifndef _TEMPLATE_STACK_INTERNAL_INCLUDED_H_
#define _TEMPLATE_STACK_INTERNAL_INCLUDED_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define _new_stack_type_internal(type) \
    struct _##type##_stack_node { \
		type d;	\
		struct _##type##_stack_node *prev;	\
		struct _##type##_stack_node *next;	\
	} typedef type##_stack_node_t; \
	\
	struct _##type##_stack { \
        struct _##type##_stack_node *top_ptr; \
        struct _##type##_stack_node *start; \
    } typedef type##_stack_t; \
    \
    void type##_stack_push(type##_stack_t **stack, type val) \
	{ \
		struct _##type##_stack_node *_##type##_stack_node_temp, *_##type##_stack_node_last; \
		if ((*stack)->start == NULL) {	\
			_template_create_node_internal(struct _##type##_stack_node, _##type##_stack_node_temp, val, NULL); \
            (*stack)->start = (*stack)->top_ptr = (struct _##type##_stack_node *)_##type##_stack_node_temp; \
			return; \
		} \
		_##type##_stack_node_last = (struct _##type##_stack_node *)(*stack)->top_ptr; \
		_template_create_node_internal(struct _##type##_stack_node, _##type##_stack_node_temp, val, _##type##_stack_node_last); \
		(*stack)->top_ptr = _##type##_stack_node_last->next = (struct _##type##_stack_node *)_##type##_stack_node_temp; \
	} \
	\
	void type##_stack_for_each(type##_stack_t **stack, void (*callback)(type elem, int index, type##_stack_t **stack)) \
	{ \
        _template_for_each_internal(struct _##type##_stack_node, (*stack), callback); \
	} \
	\
    int type##_stack_length(type##_stack_t *stack) \
	{ \
        _template_length_internal(struct _##type##_stack_node, stack); \
	} \
	\
	void *type##_stack_pop(type##_stack_t **stack) \
	{ \
        if((*stack)->top_ptr == NULL) return NULL; \
		struct _##type##_stack_node *_##type##_stack_node_temp, *_##type##_stack_node_last; \
		_##type##_stack_node_temp = (struct _##type##_stack_node *)(*stack)->top_ptr; \
		if(_##type##_stack_node_temp->prev != NULL) { \
            (*stack)->top_ptr = _##type##_stack_node_last = _##type##_stack_node_temp->prev; \
            _##type##_stack_node_last->next = NULL; \
		} \
        else \
            (*stack)->start = (*stack)->top_ptr = NULL; \
		_template_delete_node_internal(_##type##_stack_node_temp); \
		return NULL; \
	} \
	\
	void type##_stack_pop_all(type##_stack_t **stack) \
	{ \
        _template_remove_all_internal(struct _##type##_stack_node, (*stack), top_ptr); \
        (*stack)->start = (*stack)->top_ptr = NULL; \
	} \
	\
	void type##_stack_delete(type##_stack_t **stack) \
	{ \
        free(*stack); \
	}

#define _new_stack_internal(name, type) \
    type##_stack_t *name = (type##_stack_t *)malloc(sizeof(type##_stack_t)); \
    name->start = name->top_ptr = NULL;

#endif // _TEMPLATE_STACK_INTERNAL_INCLUDED_H_
