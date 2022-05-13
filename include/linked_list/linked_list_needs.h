/*
** C_Linked-List_Lib PROJECT, 2020
** linked_list_needs.h
** File description:
** Funtions prototypes and macros needed by project
** but that don't need to be seen by user
** Author:
** Arnaud Guerout
** https://github.com/Guerout-Arnaud
** Contributors:
**
*/

#ifndef LINKED_LIST_NEEDS_H_
    #define LINKED_LIST_NEEDS_H_

    #include "linked_list.h"

    #ifndef container_of
        #define container_of(ptr, type, member) ({                      \
                    const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
                    (type *)( (char *)__mptr - offsetof(type,member) );})
    #endif

    typedef struct linked_list_s linked_list_t;

    void _list_init(linked_list_t *ptr) __attribute__((no_instrument_function));
    int _list_len(linked_list_t *current) __attribute__((no_instrument_function));
    linked_list_t *_list_prev(linked_list_t *current) __attribute__((no_instrument_function));
    linked_list_t *_list_next(linked_list_t *current) __attribute__((no_instrument_function));
    linked_list_t *_list_idx(linked_list_t *current, int idx) __attribute__((no_instrument_function));
    linked_list_t *_list_add(linked_list_t *current, linked_list_t *add) __attribute__((no_instrument_function));
    linked_list_t *_list_del(linked_list_t *first, linked_list_t *remove) __attribute__((no_instrument_function));

#endif