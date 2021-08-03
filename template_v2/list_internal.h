#ifndef _TEMPLATE_LIST_INTERNAL_INCLUDED_H_
#define _TEMPLATE_LIST_INTERNAL_INCLUDED_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define _new_list_type_internal(type, adt) \
    struct _##type##_list_node { \
		type d;	\
		struct _##type##_list_node *prev;	\
		struct _##type##_list_node *next;	\
	} typedef type##_list_node_t; \
	\
	struct _##type##_list { \
        struct _##type##_list_node *curr_ptr, *end_ptr; \
        struct _##type##_list_node *start; \
    } typedef type##_list_t; \
    \
	void type##adt##insert(type##_list_t **list, type val) \
	{ \
		struct _##type##_list_node *_##type##_list_node_temp, *_##type##_list_node_last; \
		if ((*list)->start == NULL) {	\
			_template_create_node_internal(struct _##type##_list_node, _##type##_list_node_temp, val, NULL); \
            (*list)->start = (*list)->curr_ptr = (*list)->end_ptr = (struct _##type##_list_node *)_##type##_list_node_temp; \
			return; \
		} \
		_##type##_list_node_last = (struct _##type##_list_node *)(*list)->end_ptr; \
		_template_create_node_internal(struct _##type##_list_node, _##type##_list_node_temp, val, _##type##_list_node_last); \
		(*list)->end_ptr = _##type##_list_node_last->next = (struct _##type##_list_node *)_##type##_list_node_temp; \
	} \
	\
	void type##adt##for_each(type##_list_t **list, void (*callback)(type elem, int index, type##_list_t **list)) \
	{ \
        _template_for_each_internal(struct _##type##_list_node, (*list), callback); \
	} \
	\
	type type##adt##head(type##_list_t *list) \
	{ \
        return list->start->d; \
	} \
	\
	type type##adt##tail(type##_list_t *list) \
	{ \
        return list->end_ptr->d; \
	} \
	\
	int type##adt##length(type##_list_t *list) \
	{ \
        _template_length_internal(struct _##type##_list_node, list); \
	} \
	\
	void type##adt##remove(type node) \
	{ \
	} \
	\
	void *type##adt##remove_last(type##_list_t **list) \
	{ \
        if((*list)->end_ptr == NULL) return NULL; \
		struct _##type##_list_node *_##type##_list_node_temp, *_##type##_list_node_last; \
		_##type##_list_node_temp = (struct _##type##_list_node *)(*list)->end_ptr; \
		if(_##type##_list_node_temp->prev != NULL) { \
            (*list)->end_ptr = _##type##_list_node_last = _##type##_list_node_temp->prev; \
            _##type##_list_node_last->next = NULL; \
		} \
        else \
            (*list)->start = (*list)->curr_ptr = (*list)->end_ptr = NULL; \
		_template_delete_node_internal(_##type##_list_node_temp); \
		return NULL; \
	} \
	\
	void type##adt##remove_all(type##_list_t **list) \
	{ \
        _template_remove_all_internal(struct _##type##_list_node, (*list), end_ptr); \
        (*list)->start = (*list)->curr_ptr = (*list)->end_ptr = NULL; \
	} \
	\
	void type##adt##delete(type##_list_t **list) \
	{ \
        type##_list_remove_all(&(*list)); \
        free(*list); \
	}

#define _new_list_internal(name, type) \
    type##_list_t *name = (type##_list_t *)malloc(sizeof(type##_list_t)); \
    name->start = name->end_ptr = NULL;

#endif // _TEMPLATE_LIST_INTERNAL_INCLUDED_H_
