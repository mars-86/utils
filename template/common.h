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

#define _template_for_each_internal(_base_node, _this_node, callback) \
    struct _base_node *_base_node_temp; \
    int i; \
    for (i = 0, _base_node_temp = (struct _base_node *)_this_node->start; _base_node_temp != NULL; ++i, _base_node_temp = _base_node_temp->next) \
        callback(_base_node_temp->d, i, _this_node->start);

#define _template_length_internal(_base_node, _this_node) \
    struct _base_node *_base_node_temp = (struct _base_node *)_this_node->start; \
        int i = 0; \
        while (_base_node_temp != NULL) \
            ++i, _base_node_temp = _base_node_temp->next; \
        return i;

#endif // _TEMPLATE_COMMON_INCLUDED_H_
