/*
** C_Lib PROJECT, 2020
** performance.c
** File description:
** Intrumentals functions used to check the optimisation of the code
** Author:
** Arnaud Guerout
** https://github.com/Guerout-Arnaud
** Contributors:
**
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "instrument/performance.h"

static perf_t *get_call(void *target_func, void *call_site) __attribute__((no_instrument_function));

perf_t *processing = NULL;
perf_t *print = NULL;


void *main_addr = NULL;

void __cyg_profile_func_enter(void *target_func, void *call_site)
{
    if (!main_addr) {
        main_addr = target_func;
    }

    perf_t *new_call = malloc(sizeof(*new_call));

    if (new_call == NULL)
        return;
    processing = list_add(processing, new_call, list);
    list_init(new_call, list);
    new_call->target = target_func;
    new_call->caller = call_site;
    new_call->time = clock();
    return;
}

static perf_t *get_call(void *target_func, void *call_site)
{
    for (perf_t *tmp = processing; tmp != NULL; tmp = list_next(tmp, list)) {
        if (tmp->target == target_func && tmp->caller == call_site) {
            return (tmp);
        }
    }
    return (NULL);
}

void __cyg_profile_func_exit(void *target_func, void *call_site)
{
    perf_t *func_perf = get_call(target_func, call_site);

    if (func_perf == NULL) {
        return;
    }

    func_perf->time = clock() - func_perf->time;
    processing = list_del(processing, func_perf, list);
    print = list_add(print, func_perf, list);

    if (target_func == main_addr) {
        printf("\n[Performance Logger][Main Address] %p\n", target_func);
        for (perf_t *tmp = print; tmp != NULL; tmp = list_next(tmp, list))
            printf("[Performance Logger] Function %p called from %p took %ld CPU ticks to execute, representing %f seconds\n", tmp->target, tmp->caller, tmp->time, ((float)tmp->time / CLOCKS_PER_SEC));
        for (perf_t *next = NULL; print != NULL; print = next) {
            next = list_next(print, list);
            free(print);
        }
    }
    return;
}