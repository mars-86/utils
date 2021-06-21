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
	void name##_insert(const void *n) \
	{ \
		struct _##name##node *_##name##node_temp, *_##name##node_last; \
		if ((name)->next == NULL) {	\
			_create_node_internal(struct _##name##node, _##name##node_temp, ((type)n), NULL); \
            name->begin_ptr = name->curr_ptr = name->end_ptr = name->next = (struct _##name##node *)_##name##node_temp; \
			return; \
		} \
		_##name##node_last = (struct _##name##node *)name->end_ptr; \
		_create_node_internal(struct _##name##node, _##name##node_temp, ((type)n), _##name##node_last); \
		name->end_ptr = _##name##node_last->next = (struct _##name##node *)_##name##node_temp; \
	} \
	void name##_for_each(void (*callback)(const void *elem, int index, list_t **list)) \
	{ \
        struct _##name##node *_##name##node_temp; \
        int i; \
        for (i = 0, _##name##node_temp = (struct _##name##node *)name->begin_ptr; _##name##node_temp != NULL; ++i, _##name##node_temp =_##name##node_temp->next) \
            callback(_##name##node_temp->d, i, name->begin_ptr); \
	} \
	void name##_traverse(void) \
	{ \
        struct _##name##node *_##name##node_temp; \
        const char *fmt = _get_format_internal(type); \
        for (_##name##node_temp = (struct _##name##node *)name->begin_ptr; _##name##node_temp != NULL; _##name##node_temp =_##name##node_temp->next) { \
            printf(fmt, (int)&(*_##name##node_temp->d)); \
        } \
	} \
	int name##_length(void) \
	{ \
        struct _##name##node *_##name##node_temp = (struct _##name##node *)name->begin_ptr; \
        int i = 0; \
        while (_##name##node_temp != NULL) \
            ++i, _##name##node_temp =_##name##node_temp->next; \
        return i; \
	} \
	void name##_remove(const void *node) \
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
            name->begin_ptr = name->curr_ptr = name->end_ptr = name->next = NULL; \
		_delete_node_internal(_##name##node_temp); \
		return NULL; \
	} \
	void name##_remove_all(void) \
	{ \
        if(name->end_ptr == NULL) return; \
        struct _##name##node *_##name##node_temp = (struct _##name##node *)name->end_ptr; \
        while(_##name##node_temp != NULL) { \
            name->end_ptr = _##name##node_temp->prev; \
            _delete_node_internal(_##name##node_temp); \
            _##name##node_temp = (struct _##name##node *)name->end_ptr; \
        } \
        name->begin_ptr = name->curr_ptr = name->end_ptr = name->next = NULL; \
	} \
    void name##_create_list(list_t **list) { \
		*list = (list_t *)malloc(sizeof(list_t)); \
		(*list)->begin_ptr = (*list)->curr_ptr = (*list)->end_ptr = (*list)->next = NULL; \
		(*list)->insert = &name##_insert; \
		(*list)->for_each = &name##_for_each; \
		(*list)->traverse = &name##_traverse; \
		(*list)->length = &name##_length; \
		(*list)->remove = &name##_remove; \
		(*list)->remove_last = &name##_remove_last;	\
		(*list)->remove_all = &name##_remove_all; \
	} \
	name##_create_list(&name);

#endif // _TEMPLATE_LIST_INTERNAL_INCLUDED_H_
