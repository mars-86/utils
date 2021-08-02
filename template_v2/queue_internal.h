#ifndef _TEMPLATE_QUEUE_INTERNAL_INCLUDED_H_
#define _TEMPLATE_QUEUE_INTERNAL_INCLUDED_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define _new_queue_type_internal(type) \
	struct _##type##_queue_node { \
		type d;	\
		struct _##type##_queue_node *prev;	\
		struct _##type##_queue_node *next;	\
	} typedef type##_queue_node_t; \
	\
	struct _##type##_queue { \
        struct _##type##_queue_node *end_ptr; \
        struct _##type##_queue_node *start; \
    } typedef type##_queue_t; \
    \
	void type##_queue_insert(type##_queue_t **queue, type val) \
	{ \
		struct _##type##_queue_node *_##type##_queue_node_temp, *_##type##_queue_node_last; \
		if ((*queue)->start == NULL) {	\
			_template_create_node_internal(struct _##type##_queue_node, _##type##_queue_node_temp, val, NULL); \
            (*queue)->start = (*queue)->end_ptr = (struct _##type##_queue_node *)_##type##_queue_node_temp; \
			return; \
		} \
		_##type##_queue_node_last = (struct _##type##_queue_node *)(*queue)->end_ptr; \
		_template_create_node_internal(struct _##type##_queue_node, _##type##_queue_node_temp, val, _##type##_queue_node_last); \
		(*queue)->end_ptr = _##type##_queue_node_last->next = (struct _##type##_queue_node *)_##type##_queue_node_temp; \
	} \
	\
	void type##_queue_for_each(type##_queue_t **queue, void (*callback)(type elem, int index, type##_queue_t **queue)) \
	{ \
        _template_for_each_internal(struct _##type##_queue_node, (*queue), callback); \
	} \
	\
	int type##_queue_length(type##_queue_t *queue) \
	{ \
        _template_length_internal(struct _##type##_queue_node, queue); \
	} \
	\
	void *type##_queue_remove(type##_queue_t **queue) \
	{ \
        if((*queue)->start == NULL) return NULL; \
		struct _##type##_queue_node *_##type##_queue_node_temp, *_##type##_queue_node_last; \
		_##type##_queue_node_temp = (struct _##type##_queue_node *)(*queue)->start; \
		if(_##type##_queue_node_temp->next != NULL) { \
            (*queue)->start = _##type##_queue_node_last = _##type##_queue_node_temp->next; \
            _##type##_queue_node_last->prev = NULL; \
		} \
        else \
            (*queue)->start = (*queue)->end_ptr = NULL; \
		_template_delete_node_internal(_##type##_queue_node_temp); \
		return NULL; \
	} \
	\
	void type##_queue_remove_all(type##_queue_t **queue) \
	{ \
        _template_remove_all_internal(struct _##type##_queue_node, (*queue), end_ptr); \
        (*queue)->start = (*queue)->end_ptr = NULL; \
	} \
	\
	void type##_queue_delete(type##_queue_t **queue) \
	{ \
        type##_queue_remove_all(&(*queue)); \
        free(*queue); \
	}

#define _new_queue_internal(name, type) \
    type##_queue_t *name = (type##_queue_t *)malloc(sizeof(type##_queue_t)); \
    name->start = name->end_ptr = NULL;

#endif // _TEMPLATE_QUEUE_INTERNAL_INCLUDED_H_
