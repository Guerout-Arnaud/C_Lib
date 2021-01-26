/*
** C_Linked-List_Lib PROJECT, 2020
** add_del.c
** File description:
** Functions used to add or del element in a linked list
** Author:
** Arnaud Guerout
** https://github.com/Guerout-Arnaud
** Contributors:
**
*/

#include <stddef.h>
#include "linked_list.h"

linked_list_t *_list_add(linked_list_t *current, linked_list_t *add)
{
    if (current == NULL || add == NULL) {
        if (current != NULL)
            return (current);
        else
            return (add);
    }
    for (; current != NULL && current->next != NULL; current = current->next);
    current->next = add;
    add->prev = current;
    return (current);
}

linked_list_t *_list_del(linked_list_t *first, linked_list_t *remove)
{
    linked_list_t *tmp = NULL;

    if (first == NULL || remove == NULL)
            return (first);
    for (linked_list_t *current = first; current != NULL; current = current->next)
        if (current->next == remove) {
            tmp = current->next;
            current->next = tmp->next;
            tmp = tmp->next;
            if (tmp != NULL)
                tmp->prev = current;
        }
    if (first == remove) {
        tmp = first;
        first = first->next;
        if (first != NULL)
            first->prev = tmp->prev;
        if (first != NULL && first->prev != NULL)
            first->prev->next = first;
    }
    return (first);
}