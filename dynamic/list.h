#ifndef _DYNAMIC_LIST_INCLUDED_H_
#define _DYNAMIC_LIST_INCLUDED_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _list list_t;

struct _list {
	void *begin_ptr, *curr_ptr, *end_ptr;
	void (*insert)(const void *(n));
	void *(*remove_last)(void);
	void (*traverse)(void);
	void *next;
};

#define get_format(type) \
    (!strcmp(#type, "char *") ? "%s\n" : \
    !strcmp(#type, "int *") ? "%d\n" : "%d\n")

#define new_list(name, type)																	\
	struct _##name##node {																		\
		type d;																					\
		struct _##name##node *prev;																\
		struct _##name##node *next;																\
	};																							\
	void name##_insert(const void (*n))													\
	{																							\
		struct _##name##node *_##name##node_temp;												\
		_##name##node_temp = (struct _##name##node*)malloc(sizeof(struct _##name##node));		\
		if ((name)->next == NULL) {															\
			_##name##node_temp->d = (type)n;													\
			_##name##node_temp->prev = NULL;													\
			_##name##node_temp->next = NULL;													\
			name->curr_ptr = name->next = (struct _##name##node *)_##name##node_temp;		\
			struct _##name##node *_##name##node_print = (struct _##name##node *)(name)->curr_ptr; \
			printf(get_format(type), &(*_##name##node_print->d));		\
			return;																				\
		}															\
		_##name##node_temp->d = (type)n;													\
		_##name##node_temp->prev = (name)->curr_ptr;													\
		_##name##node_temp->next = NULL;													\
		name->curr_ptr = name->next = (struct _##name##node *)_##name##node_temp;		\
		struct _##name##node *_##name##node_print = (struct _##name##node *)name->curr_ptr; \
		printf(get_format(type), &(*_##name##node_print->d));		\
	}																							\
	void *name##_remove_last(void)															\
	{																							\
		struct _##name##node *_##name##node_temp;												\
		_##name##node_temp = name->curr_ptr;													\
		name->curr_ptr = _##name##node_temp->prev;											\
		free(_##name##node_temp);																\
		return NULL;																			\
	} \
	void name##_traverse(void) \
	{ \
        struct _##name##node *_##name##node_temp; \
        for (_##name##node_temp = (struct _##name##node *)name->begin_ptr; _##name##node_temp != NULL; _##name##node_temp =_##name##node_temp->next) \
            printf(get_format(type), &(*_##name##node_temp->d)); \
	} \
    void name##_create_list(list_t **list) {													\
		*list = (list_t *)malloc(sizeof(list_t));												\
		(*list)->begin_ptr = (*list)->curr_ptr = NULL;											\
		(*list)->insert = &name##_insert;														\
		(*list)->remove_last = &name##_remove_last;														\
		(*list)->traverse = &name##_traverse;	\
		(*list)->next = NULL;																	\
	}																							\
	name##_create_list(&name);

void delete_list(list_t **list)
{
    free(*(list));
}

/*
#define new_list(name, type)																	\
	struct _##name##node {																		\
		type d;																					\
		struct _##name##node *prev;																\
		struct _##name##node *next;																\
	};																							\
	void name##_insert(list_t **list, const void *n)													\
	{																							\
		struct _##name##node *_##name##node_temp;												\
		_##name##node_temp = (struct _##name##node*)malloc(sizeof(struct _##name##node));		\
		if ((*list)->next == NULL) {															\
			_##name##node_temp->d = (type)n;													\
			_##name##node_temp->prev = NULL;													\
			_##name##node_temp->next = NULL;													\
			(*list)->curr_ptr = (*list)->next = (struct _##name##node *)_##name##node_temp;		\
			struct _##name##node *_##name##node_print = (struct _##name##node *)(*list)->curr_ptr; \
			printf("%d\n", &(*_##name##node_print->d));		\
			return;																				\
		}															\
		_##name##node_temp->d = (type)n;													\
		_##name##node_temp->prev = (*list)->curr_ptr;													\
		_##name##node_temp->next = NULL;													\
		(*list)->curr_ptr = (*list)->next = (struct _##name##node *)_##name##node_temp;		\
		struct _##name##node *_##name##node_print = (struct _##name##node *)(*list)->curr_ptr; \
		printf("%d\n", &(*_##name##node_print->d));		\
	}																							\
	void *name##_remove_last(list_t **list)															\
	{																							\
		struct _##name##node *_##name##node_temp;												\
		_##name##node_temp = (*list)->curr_ptr;													\
		(*list)->curr_ptr = _##name##node_temp->prev;											\
		free(_##name##node_temp);																\
		return NULL;																			\
	}																							\
	void name##_create_list(list_t **list) {													\
		*list = (list_t *)malloc(sizeof(list_t));												\
		(*list)->begin_ptr = (*list)->curr_ptr = NULL;											\
		(*list)->insert = &name##_insert;														\
		(*list)->remove_last = &name##_remove_last;														\
		(*list)->next = NULL;																	\
	}																							\
	name##_create_list(&name);


void delete_list(list_t **list)
{
    free(*(list));
}
*/

/*
#define list(type, name) \
	struct _##name##node { \
		type d; \
		struct _##name##node *prev; \
		struct _##name##node *next; \
	}; \
	struct _##name { \
		struct _##name##node *begin_ptr, *curr_ptr; \
		void (*push)(struct _##name **list, type n); \
		struct _##name##node *(*pop)(struct _##name **list); \
		struct _##name##node *next; \
	}; \
	struct _##name name; \
	void name##_push(struct _##name **list, type n) \
	{ \
		struct _##name##node *_##name##node_temp; \
		_##name##node_temp = (struct _##name##node*)malloc(sizeof(struct _##name##node)); \
		if (name.next == NULL) { \
			name.curr_ptr = name.next = _##name##node_temp; \
			name.next->d = n; \
			name.next->prev = NULL; \
			name.next->next = NULL; \
			return; \
		} \
		printf("Soy foo push\n"); \
	} \
	struct _##name##node *name##_pop(struct _##name **list) \
	{ \
		struct _##name##node *_##name##node_temp; \
		_##name##node_temp = name.curr_ptr; \
		name.curr_ptr = name.curr_ptr->prev; \
		free(_##name##node_temp); \
		return NULL; \
	} \
	name.push = &name##_push; \
	name.pop = &name##_pop;
*/

#endif // _DYNAMIC_LIST_INCLUDED_H_
