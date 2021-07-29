#ifndef _TEMPLATE_COMMON_INCLUDED_H_
#define _TEMPLATE_COMMON_INCLUDED_H_

#define _template_create_node_internal(_node_base_type, _node_dest, _val, _node_prev) \
( \
     _node_dest = (_node_base_type *)malloc(sizeof(_node_base_type)), \
    (_node_dest)->d = _val, \
    (_node_dest)->prev = _node_prev, \
    (_node_dest)->next = NULL \
)

#define _template_delete_node_internal(_node) \
( \
    free(_node) \
)

#define _template_get_format_internal(_type) \
( \
    !strcmp(#_type, "char *") ? "%s\n" : \
    !strcmp(#_type, "int *") ? "%d\n" : \
    !strcmp(#_type, "long *") ? "%ld\n" : "%d\n" \
)

#define _template_for_each_internal(_node_base_type, _this_node, callback) \
    _node_base_type *_base_node_temp; \
    int i; \
    for (i = 0, _base_node_temp = (_node_base_type *)_this_node->start; _base_node_temp != NULL; ++i, _base_node_temp = _base_node_temp->next) \
        callback(_base_node_temp->d, i, _this_node->start);

#define _template_length_internal(_node_base_type, _this_node) \
    _node_base_type *_base_node_temp = (_node_base_type *)_this_node->start; \
    int i = 0; \
    while (_base_node_temp != NULL) \
        ++i, _base_node_temp = _base_node_temp->next; \
    return i;

#define _template_remove_all_internal(_base_node_type, _this_node, _this_node_back_ptr) \
    if(_this_node->_this_node_back_ptr == NULL) return; \
    _base_node_type *_base_node_temp = (_base_node_type *)_this_node->_this_node_back_ptr; \
    while(_base_node_temp != NULL) { \
        _this_node->_this_node_back_ptr = _base_node_temp->prev; \
        _template_delete_node_internal(_base_node_temp); \
        _base_node_temp = (_base_node_type *)_this_node->_this_node_back_ptr; \
    } \

#endif // _TEMPLATE_COMMON_INCLUDED_H_
