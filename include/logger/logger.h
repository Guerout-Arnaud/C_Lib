/*
** C_Logger_Lib PROJECT, 2020
** logger.h
** File description:
** Necessary prototypes, structures and defines that have allow use of logger
** Author:
** Arnaud Guerout
** https://github.com/Guerout-Arnaud
** Contributors:
**
*/

#ifndef LIB_LOGGER_H_
    #define LIB_LOGGER_H_

    #include <stdbool.h>
    #include <stdio.h>
    #include <pthread.h>

    #define RESET           "\033[0m"
    #define BOLD(msg)       "\033[1m" msg RESET
    #define BLINK(msg)      "\033[5m" msg RESET

    #define YELLOW(msg)     "\033[38;5;11m" msg RESET
    #define ORANGE(msg)     "\033[38;5;208m" msg RESET
    #define RED(msg)        "\033[38;5;196m" msg RESET
    #define BLUE(msg)       "\033[38;5;27m" msg RESET
    #define GREEN(msg)      "\033[38;5;46m" msg RESET
    #define PURPLE(msg)     "\033[38;5;164m" msg RESET

    #define OK(msg) BOLD(GREEN(msg))
    #define KO(msg) BOLD(RED(msg))

    typedef enum log_type_e {
        LOG_NONE    = 0x01,
        LOG_INFO    = 0x02,
        LOG_WARN    = 0x04,
        LOG_ERROR   = 0x08,
        LOG_DEBUG   = 0x10,
        LOG_UNKNOWN = 0x20
    } log_type_t;

    typedef struct logger_s {
        bool debug;
        bool thread;
        int fds_len;
        FILE **fds;
        pthread_mutex_t mutex;
    } logger_t;

    int logger_init(bool debug, bool thread, bool use_stdout);
    void logger_destroy();
    int logger_add_filename(char *file_name);
    int logger_add_file(FILE *file);
    void log_msg(log_type_t type, char *format, ...);

#endif