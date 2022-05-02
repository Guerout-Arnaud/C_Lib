/*
** Projects PROJECT, 2020
** logger.c
** File description:
** Print function for log lib
** Author:
** Arnaud Guerout
** https://github.com/Guerout-Arnaud
** Contributors:
**
*/

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logger.h"
#include "logger_constants.h"

static char *log_time(void)
{
    struct tm gmt = {0};
    time_t elapsed = time(NULL);
    char *str = NULL;

    if (&gmt != gmtime_r(&elapsed, &gmt))
        return (UNKNOWN_TIME);
    if (asprintf(&str, "[%04d/%02d/%02d %02d:%02d:%02d] ",
        gmt.tm_year + 1900, gmt.tm_mon + 1, gmt.tm_mday,
        gmt.tm_hour, gmt.tm_min, gmt.tm_sec) != 22) {
        if (str != NULL)
            free(str);
        return (UNKNOWN_TIME);
    }
    return (str);
}

int get_log_type_str_idx(log_type_t type)
{
    int pow = 0;
    log_type_t found_type = 1;

    if (type <= 0)
        type = LOG_UNKNOWN;
    for (found_type = 1; found_type < type;
        found_type = found_type << 1, pow++);
    if (found_type != type) {
        type = LOG_UNKNOWN;
        for (found_type = 1; found_type < type;
            found_type = found_type << 1, pow++);
    }
    return (pow);
}

static char *build_log_print_message(logger_t *logger, log_type_t type, int nb)
{
    char *msg = NULL;
    char *time_str = log_time();
    int bytes = 0;

    if (nb < 0 || type > (LOG_DEBUG | LOG_ERROR))
        return (NULL_MSG);
    if (type < LOG_DEBUG) {
        bytes = asprintf(&msg, "%s%s%s", time_str,
            LOG_TYPE_PRINT[get_log_type_str_idx(type)], logger->msg);
    } else {
        bytes = asprintf(&msg, "%s%s%s%s",  time_str,
            LOG_TYPE_PRINT[get_log_type_str_idx(LOG_DEBUG)],
            LOG_TYPE_PRINT[get_log_type_str_idx(type & ~LOG_DEBUG)], logger->msg);
    }
    if (bytes < 0)
        msg = logger->msg;
    if (time_str != NULL && time_str != UNKNOWN_TIME)
        free(time_str);
    if (msg == NULL && type < LOG_DEBUG)
        msg = NULL_MSG;
    return (msg);
}

static char *build_log_file_message(logger_t *logger, log_type_t type, int nb)
{
    char *msg = NULL;
    char *time_str = log_time();
    int bytes = 0;

    if (nb < 0 || type > (LOG_DEBUG | LOG_ERROR))
        return (NULL_MSG);
    if (type < LOG_DEBUG) {
        bytes = asprintf(&msg, "%s%s%s", time_str,
            LOG_TYPE_FILE[get_log_type_str_idx(type)], logger->msg);
    } else {
        bytes = asprintf(&msg, "%s%s%s%s",  time_str,
            LOG_TYPE_FILE[get_log_type_str_idx(LOG_DEBUG)],
            LOG_TYPE_FILE[get_log_type_str_idx(type - LOG_DEBUG)], logger->msg);
    }
    if (bytes < 0)
        msg = logger->msg;
    if (time_str != NULL && time_str != UNKNOWN_TIME)
        free(time_str);
    if (msg == NULL && type < LOG_DEBUG)
        msg = NULL_MSG;
    return (msg);
}

void log_msg(logger_t *logger, log_type_t type, int nb)
{
    char *print = NULL;
    char *file = NULL;

    if (logger == NULL)
        return;
    if (logger->debug == false && type >= LOG_DEBUG) {
        if (logger->msg != NULL)
            free(logger->msg);
        logger->msg = NULL;
        return;
    }
    if (logger->std_output == true) {
        print = build_log_print_message(logger, type, nb);
        dprintf(1, "%s", print);
    }
    if (logger->fd > -1) {
        file = build_log_file_message(logger, type, nb);
        dprintf(logger->fd, "%s", file);
    }
    if (print != NULL_MSG && print != logger->msg)
        free(print);
    if (file != NULL_MSG && file != logger->msg)
        free(file);
    if (logger->msg != NULL)
        free(logger->msg);
    logger->msg = NULL;
    return;
}