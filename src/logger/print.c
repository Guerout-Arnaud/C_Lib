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

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include <pthread.h>
#include <unistd.h>

#include "logger_constants.h"
#include "logger.h"

extern logger_t logger;

static char *get_time_str(char *time_str)
{
    struct tm gmt = {0};
    time_t elapsed = time(NULL);
    int test = 0;

    if (&gmt != gmtime_r(&elapsed, &gmt) ||
        (test = snprintf(time_str, LOG_TIME_STR_LEN + 1, "[%04d/%02d/%02d %02d:%02d:%02d]",
        gmt.tm_year + 1900, gmt.tm_mon + 1, gmt.tm_mday,
        gmt.tm_hour, gmt.tm_min, gmt.tm_sec)) != (int) LOG_TIME_STR_LEN)
    {
        strcpy(time_str, UNKNOWN_TIME);
    }

    return (time_str);
}

static int get_type_idx(log_type_t type)
{
    int idx = 0;
    log_type_t found_type = LOG_NONE;

    if (type <= 0)
        type = LOG_UNKNOWN;

    for (found_type = 1; found_type < type; found_type = found_type << 1, idx++);

    if (found_type != type) {
        type = LOG_UNKNOWN;
        for (found_type = 1; found_type < type; found_type = found_type << 1, idx++);
    }

    return (idx);
}

void log_msg(log_type_t type, char *format, ...)
{
    if (logger.debug == false && type & LOG_DEBUG) {
        return;
    }

    char time_str[LOG_TIME_STR_LEN + 1] = {0};
    int debug = 0;
    va_list args = {0};

    va_start(args, format);

    get_time_str(time_str);

    if (type & LOG_DEBUG) {
        debug = get_type_idx(LOG_DEBUG);
        type = type & ~LOG_DEBUG;
    }

    if (logger.thread == true) {
        pthread_mutex_lock(&logger.mutex);
    }

    for (int i = 0; i < logger.fds_len; i++) {
        if (logger.fds[i] == stdout) {
            FILE *output = NULL;
            if (type & LOG_WARN || type & LOG_ERROR) {
                output = stderr;
            } else {
                output = stdout;
            }
            fprintf(output, "%s %s%s", time_str, LOG_TYPE_PRINT[debug], LOG_TYPE_PRINT[get_type_idx(type)]);
            vfprintf(output, format, args);
            fflush(output);
        } else {
            fprintf(logger.fds[i], "%s %s%s", time_str, LOG_TYPE_FILE[debug], LOG_TYPE_FILE[get_type_idx(type)]);
            vfprintf(logger.fds[i], format, args);
            fflush(logger.fds[i]);
        }
    }

    if (logger.thread == true) {
        pthread_mutex_unlock(&logger.mutex);
    }

    va_end(args);
}