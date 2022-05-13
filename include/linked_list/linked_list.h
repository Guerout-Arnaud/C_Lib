/*
** C_Linked-List_Lib PROJECT, 2020
** linked_list.h
** File description:
** I Don't Know Yet
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_

    #include <stddef.h>
    #include "linked_list_needs.h"

    #define list_typename(x) _Generic((x), \
        struct linked_list_s: "struct linked_list_s", \
        struct linked_list_s *: "pointer to struct linked_list_s", \
        default: "other")

    typedef struct linked_list_s {
        struct linked_list_s *prev;
        struct linked_list_s *next;
    } linked_list_t;

    #define list_init(element, field) \
    __extension__ ({ \
        typeof(element) _list_rtn = element; \
\
        if (_list_rtn != NULL) { \
            _list_init(&(element)->field); \
        } \
        _list_rtn; \
    })

    #define list_len(list, field) \
    __extension__ ({ \
        int _list_rtn = 0; \
\
        if (list != NULL) { \
           _list_rtn = _list_len(&(list)->field); \
        } \
        _list_rtn; \
    })

    #define list_prev(list, field) \
    __extension__ ({ \
        typeof(list) _list_rtn = list; \
        linked_list_t *_list_head = NULL; \
\
        if (_list_rtn != NULL) { \
            _list_head = _list_prev(&(list)->field); \
            if (_list_head != NULL) \
                _list_rtn = container_of(_list_head, typeof(*(list)), field); \
            else \
                _list_rtn = NULL; \
        } \
        _list_rtn; \
    })

    #define list_next(list, field) \
    __extension__ ({ \
        typeof(list) _list_rtn = list; \
        linked_list_t *_list_head = NULL; \
\
        if (_list_rtn != NULL) { \
            _list_head = _list_next(&(list)->field); \
            if (_list_head != NULL) \
                _list_rtn = container_of(_list_head, typeof(*(list)), field); \
            else \
                _list_rtn = NULL; \
        } \
        _list_rtn; \
    })

    #define list_idx(list, field, idx) \
    __extension__ ({ \
        typeof(list) _list_rtn = list; \
        linked_list_t *_list_head = NULL; \
\
        if (_list_rtn != NULL && sizeof(idx) == sizeof(int)) { \
            _list_head = _list_idx(&(list)->field, idx); \
            if (_list_head != NULL) \
                _list_rtn = container_of(_list_head, typeof(*(list)), field); \
            else \
                _list_rtn = NULL; \
        } \
        _list_rtn; \
    })

    #define list_add(list, add, field) \
    __extension__ ({ \
        typeof(list) _list_rtn = list; \
\
        if (_list_rtn != NULL && add != NULL) \
            _list_add(&_list_rtn->field, &(add)->field); \
        else if (add != NULL)\
            _list_rtn = add; \
        _list_rtn; \
    })

    #define list_del(list, del, field) \
    __extension__ ({ \
        typeof(list) _list_rtn = list; \
        linked_list_t *_list_head = NULL; \
\
        if (_list_rtn != NULL && del != NULL) { \
            _list_head = _list_del(&_list_rtn->field, &(del)->field); \
            if (_list_head != NULL) \
                _list_rtn = container_of(_list_head, typeof(*(list)), field); \
            else \
                _list_rtn = NULL; \
        } \
        _list_rtn; \
    })


#endif