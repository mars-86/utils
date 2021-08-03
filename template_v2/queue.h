#ifndef _TEMPLATE_QUEUE_INCLUDED_H_
#define _TEMPLATE_QUEUE_INCLUDED_H_

#include "queue_internal.h"

#define new_queue_type(type) _new_queue_type_internal(type)
#define new_queue(name, type) _new_queue_internal(name, type)

#endif // _TEMPLATE_QUEUE_INCLUDED_H_
