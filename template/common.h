#ifndef _TEMPLATE_COMMON_INCLUDED_H_
#define _TEMPLATE_COMMON_INCLUDED_H_

#define _create_node_internal(_node_base_type, _node_dest, _val, _node_prev) \
( \
     _node_dest = (_node_base_type *)malloc(sizeof(_node_base_type)), \
    (_node_dest)->d = _val, \
    (_node_dest)->prev = _node_prev, \
    (_node_dest)->next = NULL \
)

#define _delete_node_internal(_node) \
( \
    free(_node) \
)

#define _get_format_internal(_type) \
( \
    !strcmp(#_type, "char *") ? "%s\n" : \
    !strcmp(#_type, "int *") ? "%d\n" : \
    !strcmp(#_type, "long *") ? "%ld\n" : "%d\n" \
)

#endif // _TEMPLATE_COMMON_INCLUDED_H_
