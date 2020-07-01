/*
** C_Linked-List_Lib PROJECT, 2020
** init_len.c
** File description:
** Functions used to init an element and get length of a linked list
** Author:
** Arnaud Guerout
** https://github.com/Guerout-Arnaud
** Contributors:
**
*/

#include <stddef.h>
#include "linked_list.h"

void _list_init(linked_list_t *ptr)
{
    ptr->next = NULL;
    ptr->prev = NULL;
    return;
}

int _list_len(linked_list_t *current)
{
    int len = 0;
    for (; current != NULL; current = current->next, len++);
    return (len);
}