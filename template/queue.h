#ifndef _TEMPLATE_QUEUE_INCLUDED_H_
#define _TEMPLATE_QUEUE_INCLUDED_H_

#include "queue_internal.h"

#define new_queue(name, type) _new_queue_internal(name, type)

struct _queue {
	void *end_ptr;
	void (*insert)(const void *val);
	void (*traverse)(void);
	int (*length)(void);
	void *(*remove)(void);
	void (*remove_all)(void);
	void *start;
};

typedef struct _queue queue_t;

void delete_queue(queue_t **queue);

#endif // _TEMPLATE_QUEUE_INCLUDED_H_
