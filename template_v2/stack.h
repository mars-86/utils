#ifndef _TEMPLATE_STACK_INCLUDED_H_
#define _TEMPLATE_STACK_INCLUDED_H_

#include "stack_internal.h"

#define new_stack_type(type) _new_stack_type_internal(type)
#define new_stack(name, type) _new_stack_internal(name, type)

#endif // _TEMPLATE_LIST_INCLUDED_H_
