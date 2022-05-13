#include <stdio.h>
#include "linked_list.h"

typedef struct test_s
{
    int id;
    linked_list_t list;
} test_t;


void init_test(test_t *ptr)
{
    static int uuid = 0;

    ptr->id = uuid++;
    list_init(ptr, list);
}

int main (int argc, char **argv)
{
    test_t head = {0};
    test_t body = {0};
    test_t tail = {0};

    printf("\n");

    printf("Initiating elements...\n");
    init_test(&head);
    init_test(&body);
    init_test(&tail);
    printf("Elements initiated\n");

    printf("\n");

    printf("Adding elements...\n");
    test_t *new_head = NULL;
    new_head = list_add(new_head, &head, list);
    printf("head added\nnew_head =\t%p\nhead =\t\t%p\n\n", new_head, &head);
    new_head = list_add(new_head, &body, list);
    printf("body added\nnew_head->next =\t%p\nbody =\t\t\t%p\n\n", list_next(new_head, list), &body);
    new_head = list_add(new_head, &tail, list);
    printf("tail added\nnew_head[2] =\t%p\ntail =\t\t%p\n\n", list_idx(new_head, list, 2), &tail);
    printf("Elements added\n");

    printf("\n");

    printf("Checking if list is circular...\n");
    if (list_prev(new_head, list) != NULL)
        printf("List is circular\n");
    else
        printf("List is not circular\nSize of the list is : %d\n", list_len(new_head, list));

    printf("\n");

    printf("Removing elements...\n");
    test_t *old_head = new_head;
    printf("Removing body...\n");
    printf("body removed\t%p\nold_head =\t%p\nnew_head =\t%p\n\nnew_head[1] =\t%p\ntail =\t\t%p\n\n\n", &body, old_head, new_head = list_del(new_head, &body, list), list_idx(new_head, list, 1), &tail);
    printf("Removing head...\n");
    printf("head removed\t%p\nold_head =\t%p\nnew_head =\t%p\n\nCurrent len is :\t%d\nnew_head[1] =\t%p\n\n\n", &head, old_head, new_head = list_del(new_head, &head, list), list_len(new_head, list), list_idx(new_head, list, 1));
    printf("Removing tail...\n");
    printf("tail removed\t%p\nold_head =\t%p\nnew_head =\t%p\n", &tail, old_head, new_head = list_del(new_head, &tail, list));
    printf("Elements removed\n");

    printf("\n");

    return (0);
}