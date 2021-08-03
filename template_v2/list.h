#ifndef _TEMPLATE_LIST_INCLUDED_H_
#define _TEMPLATE_LIST_INCLUDED_H_

#include "list_internal.h"

#define new_list_type(type) _new_list_type_internal(type, _list_)
#define new_list(name, type) _new_list_internal(name, type)

#endif // _TEMPLATE_LIST_INCLUDED_H_
