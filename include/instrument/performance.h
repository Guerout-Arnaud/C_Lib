/*
** C_Lib PROJECT, 2020
** performance.h
** File description:
** Intrumentals functions used to check the optimisation of the code
** Author:
** Arnaud Guerout
** https://github.com/Guerout-Arnaud
** Contributors:
**
*/

#include <time.h>
#include "linked_list/linked_list.h"

#define test (x) \
    ({typeof () })

typedef struct perf_s {
    void *target;
    void *caller;
    clock_t time;
    linked_list_t list;
} perf_t;

void __cyg_profile_func_enter(void *target_func, void *call_site) __attribute__((no_instrument_function));
void __cyg_profile_func_exit(void *target_func, void *call_site) __attribute__((no_instrument_function));