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
        LOG_NONE = 1,
        LOG_INFO = 2,
        LOG_WARN = 4,
        LOG_ERROR = 8,
        LOG_DEBUG = 16,
        LOG_UNKNOWN = 32
    } log_type_t;

    typedef struct logger_s {
        bool debug;
        bool std_output;
        int fd;
        char *msg;
    } logger_t;

    logger_t *create_logger(bool std_output, bool file, char *file_path, bool debug);
    void log_msg(logger_t *logger, log_type_t type, int wrote_bytes);
    void delete_logger(logger_t *logger);

#endif