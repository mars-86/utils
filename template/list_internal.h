#ifndef _TEMPLATE_LIST_INTERNAL_INCLUDED_H_
#define _TEMPLATE_LIST_INTERNAL_INCLUDED_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define _new_list_internal(name, type) \
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
            name->start = name->curr_ptr = name->end_ptr = (struct _##name##node *)_##name##node_temp; \
			return; \
		} \
		_##name##node_last = (struct _##name##node *)name->end_ptr; \
		_create_node_internal(struct _##name##node, _##name##node_temp, val, _##name##node_last); \
		name->end_ptr = _##name##node_last->next = (struct _##name##node *)_##name##node_temp; \
	} \
	void name##_for_each(void (*callback)(type elem, int index, list_t **list)) \
	{ \
        _template_for_each_internal(struct _##name##node, name, callback); \
	} \
	int name##_length(void) \
	{ \
        _template_length_internal(struct _##name##node, name); \
	} \
	void name##_remove(type node) \
	{ \
	} \
	void *name##_remove_last(void) \
	{ \
        if(name->end_ptr == NULL) return NULL; \
		struct _##name##node *_##name##node_temp, *_##name##node_last; \
		_##name##node_temp = (struct _##name##node *)name->end_ptr; \
		if(_##name##node_temp->prev != NULL) { \
            name->end_ptr = _##name##node_last = _##name##node_temp->prev; \
            _##name##node_last->next = NULL; \
		} \
        else \
            name->start = name->curr_ptr = name->end_ptr = NULL; \
		_delete_node_internal(_##name##node_temp); \
		return NULL; \
	} \
	void name##_remove_all(void) \
	{ \
        _template_remove_all_internal(struct _##name##node, name, end_ptr); \
        name->start = name->curr_ptr = name->end_ptr = NULL; \
	} \
    void name##_create_list(list_t **list) { \
		*list = (list_t *)malloc(sizeof(list_t)); \
		(*list)->start = (*list)->curr_ptr = (*list)->end_ptr = NULL; \
		(*list)->insert = &name##_insert; \
		(*list)->for_each = &name##_for_each; \
		(*list)->length = &name##_length; \
		(*list)->remove = &name##_remove; \
		(*list)->remove_last = &name##_remove_last;	\
		(*list)->remove_all = &name##_remove_all; \
	} \
	name##_create_list(&name);

#endif // _TEMPLATE_LIST_INTERNAL_INCLUDED_H_
