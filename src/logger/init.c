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

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "logger.h"
#include "logger_constants.h"

static int open_log_file(char *file_path)
{
    int fd = -1;
    char *log_file = NULL;
    time_t elapsed = 0;
    struct tm gmt = {0};

    if (file_path == NULL) {
        elapsed = time(NULL);
        if (&gmt != gmtime_r(&elapsed, &gmt) || asprintf(&log_file,
            "logs/%d-%02d-%02d_%02d-%02d.log",  gmt.tm_year + 1900,
            gmt.tm_mon + 1, gmt.tm_mday, gmt.tm_hour, gmt.tm_min) != 25) {
            if (log_file != NULL)
                free(log_file);
            log_file = NULL;
        }
    } else
        log_file = file_path;
    if (log_file != NULL) {
        fd = open(log_file, (O_CREAT | O_WRONLY | O_TRUNC),
            (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
        if (log_file != file_path)
            free(log_file);
    }
    return(fd);
}

static void legend_log(int fd)
{
    struct tm gmt = {0};
    time_t elapsed = time(NULL);

    dprintf(fd, "Log File Created.\n");
    if (&gmt == gmtime_r(&elapsed, &gmt)) {
        dprintf(fd, "Log started on : %04d/%02d/%02d (YYYY/MM/DD)\n",
            gmt.tm_year + 1900, gmt.tm_mon + 1, gmt.tm_mday);
        dprintf(fd, "Log started at : %02d:%02d:%02d (HH:MM:SS)\n",
            gmt.tm_hour, gmt.tm_min, gmt.tm_sec);
    } else {
        dprintf(fd, "Log started on : 0001/01/01 (YYYY/MM/DD)\n");
        dprintf(fd, "Log started at : 00:00:00 (HH:MM:SS)\n");
    }
    dprintf(fd, "\n");
    dprintf(fd, "Logs will be fomated like so :\n");
    dprintf(fd, "[Date (YYYY/MM/DD)] [TYPE 1]"
        "[Type 2 (if DEBUG active)] Log Message\n");
    dprintf(fd, "\n");
    dprintf(fd, "Logs Starts Now.\n");
    dprintf(fd, "\n");
    return;
}

logger_t *create_logger(bool std_output, bool file, char *file_path, bool debug)
{
    logger_t *logger = malloc(sizeof(*logger));

    if (logger != NULL) {
        logger->debug = debug;
        logger->msg = NULL;
        logger->std_output = std_output;
        if (file == true) {
            logger->fd = open_log_file(file_path);
            if (logger->fd != -1)
                legend_log(logger->fd);
        } else
            logger->fd = -1;
    }
    return (logger);
}

void delete_logger(logger_t *logger)
{
    if (logger != NULL) {
        if (logger->fd != -1)
            close(logger->fd);
        if (logger->msg != NULL)
            free(logger->msg);
        free(logger);
    }
    return;
}