/*
** C_Logger_Lib PROJECT, 2020
** init.c
** File description:
** Ctor/Dtor of logger
** Author:
** Arnaud Guerout
** https://github.com/Guerout-Arnaud
** Contributors:
**
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "logger.h"

logger_t logger = {0};
static bool log_is_init = false;

int logger_add_file(FILE *file)
{
    FILE **tmp_fds = NULL;

    if (file == NULL) {
        return (-1);
    }

    if (logger.thread == true) {
        pthread_mutex_lock(&logger.mutex);
    }

    tmp_fds = realloc(logger.fds, sizeof(*logger.fds) * (logger.fds_len + 1));
    if (tmp_fds == NULL) {
        if (logger.thread == true) {
            pthread_mutex_unlock(&logger.mutex);
        }
        return (-1);
    }
    logger.fds = tmp_fds;

    logger.fds[logger.fds_len] = file;
    logger.fds_len++;

    if (logger.thread == true) {
        pthread_mutex_unlock(&logger.mutex);
    }
    return (0);
}

int logger_add_filename(char *file_name)
{
    FILE *file = NULL;

    if (file_name == NULL) {
        return (-1);
    }

    file = fopen(file_name, "w+");

    return (logger_add_file(file));
}

void logger_destroy()
{
    if (log_is_init == false) {
        return;
    }
    log_is_init = false;

    for (int i = 0; i < logger.fds_len; i++) {
        if (logger.fds[i] != stdout)
            fclose(logger.fds[i]);
    }
    if (logger.fds != NULL) {
        free(logger.fds);
    }
    if (logger.thread == true){
        pthread_mutex_destroy(&logger.mutex);
    }
    return;
}

int logger_init(bool debug, bool thread, bool use_stdout)
{
    if (log_is_init == true) {
        return (0);
    }
    log_is_init = true;

    logger.debug = debug;

    logger.thread = thread;
    if (logger.thread == true){
        if (pthread_mutex_init(&logger.mutex, NULL) != 0) {
            return (-1);
        }
    }

    if (use_stdout == true) {
        if (logger_add_file(stdout) == -1) {
            logger_destroy();
            return (-1);
        }
    }
    return (0);
}