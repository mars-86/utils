#ifndef _TEMPLATE_QUEUE_INTERNAL_INCLUDED_H_
#define _TEMPLATE_QUEUE_INTERNAL_INCLUDED_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define _new_queue_internal(name, type) \
	struct _##name##node { \
		type d;	\
		struct _##name##node *prev;	\
		struct _##name##node *next;	\
	}; \
	void name##_insert(type val) \
	{ \
		struct _##name##node *_##name##node_temp, *_##name##node_last; \
		if ((name)->start == NULL) {	\
			_create_node_internal(struct _##name##node, _##name##node_temp, val, NULL); \
            name->start = name->end_ptr = (struct _##name##node *)_##name##node_temp; \
			return; \
		} \
		_##name##node_last = (struct _##name##node *)name->end_ptr; \
		_create_node_internal(struct _##name##node, _##name##node_temp, val, _##name##node_last); \
		name->end_ptr = _##name##node_last->next = (struct _##name##node *)_##name##node_temp; \
	} \
	void name##_for_each(void (*callback)(type elem, int index, queue_t **queue)) \
	{ \
        _template_for_each_internal(struct _##name##node, name, callback); \
	} \
	int name##_length(void) \
	{ \
        _template_length_internal(struct _##name##node, name); \
	} \
	void *name##_remove(void) \
	{ \
        if(name->start == NULL) return NULL; \
		struct _##name##node *_##name##node_temp, *_##name##node_last; \
		_##name##node_temp = (struct _##name##node *)name->start; \
		if(_##name##node_temp->next != NULL) { \
            name->start = _##name##node_last = _##name##node_temp->next; \
            _##name##node_last->prev = NULL; \
		} \
        else \
            name->start = name->end_ptr = NULL; \
		_delete_node_internal(_##name##node_temp); \
		return NULL; \
	} \
	void name##_remove_all(void) \
	{ \
        _template_remove_all_internal(struct _##name##node, name, end_ptr); \
        name->start = name->end_ptr = NULL; \
	} \
    void name##_create_list(queue_t **queue) { \
		*queue = (queue_t *)malloc(sizeof(queue_t)); \
		(*queue)->start = (*queue)->end_ptr = NULL; \
		(*queue)->insert = &name##_insert; \
		(*queue)->for_each = &name##_for_each; \
		(*queue)->length = &name##_length; \
		(*queue)->remove = &name##_remove;	\
		(*queue)->remove_all = &name##_remove_all; \
	} \
	name##_create_list(&name);

#endif // _TEMPLATE_QUEUE_INTERNAL_INCLUDED_H_
