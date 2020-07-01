/*
** C_Linked-List_Lib PROJECT, 2020
** prev_next_idx.c
** File description:
** Functions used to get element being previous,
** next or at a certain index of linked list
** Author:
** Arnaud Guerout
** https://github.com/Guerout-Arnaud
** Contributors:
**
*/

#include <stddef.h>
#include "linked_list.h"

linked_list_t *_list_prev(linked_list_t *current)
{
    linked_list_t *prev = NULL;

    if (current != NULL)
        prev = current->prev;
    return (prev);
}

linked_list_t *_list_next(linked_list_t *current)
{
    linked_list_t *next = NULL;

    if (current != NULL)
        next = current->next;
    return (next);
}

linked_list_t *_list_idx(linked_list_t *current, int idx)
{
    for (int i = 0; current != NULL && i < idx; current = current->next, i++);
    return (current);
}