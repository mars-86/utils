#ifndef _TEMPLATE_QUEUE_INCLUDED_H_
#define _TEMPLATE_QUEUE_INCLUDED_H_

#include "queue_internal.h"

#define new_queue(name, type) _new_queue_internal(name, type)

typedef struct _queue queue_t;

struct _queue {
	void *end_ptr;
	void (*insert)(const void *val);
	void (*for_each)(void (*callback)(const void *elem, int index, queue_t **queue));
	int (*length)(void);
	void *(*remove)(void);
	void (*remove_all)(void);
	void *start;
};

void delete_queue(queue_t **queue);

#endif // _TEMPLATE_QUEUE_INCLUDED_H_
