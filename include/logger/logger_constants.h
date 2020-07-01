/*
** C_Logger_Lib PROJECT, 2020
** logger_constants.h
** File description:
** Constants used in logger that have not to be used by user
** Author:
** Arnaud Guerout
** https://github.com/Guerout-Arnaud
** Contributors:
**
*/

#ifndef LIB_LOGGER_CONSTANTS_H_
    #define LIB_LOGGER_CONSTANTS_H_

    #include "logger.h"

    #define NULL_STR            ""
    #define INFO_STR            "[INFO] "
    #define WARN_STR            "[WARNING] "
    #define ERROR_STR           "[ERROR] "
    #define DEBUG_STR           "[DEBUG] "
    #define UNKNOWN_TYPE_STR    "[UNKNOWN TYPE] "

    #define INFO_STR_C          "[" BOLD(YELLOW("INFO")) "] "
    #define WARN_STR_C          "[" BOLD(ORANGE("WARNING")) "] "
    #define ERROR_STR_C         "[" BLINK(BOLD(RED("ERROR"))) "] "
    #define DEBUG_STR_C         "[" BOLD(BLUE("DEBUG")) "] "
    #define UNKNOWN_TYPE_STR_C  "[" BOLD(PURPLE("UNKNOWN TYPE")) "] "

    static char NULL_MSG[] = ERROR_STR "An error occur while building log message\n";
    static char UNKNOWN_TIME[] = "[0001/01/01 00:00:00] ";

    static const char *LOG_TYPE_PRINT[] = {NULL_STR, INFO_STR_C, WARN_STR_C, ERROR_STR_C, DEBUG_STR_C, UNKNOWN_TYPE_STR_C};
    static const char *LOG_TYPE_FILE[] = {NULL_STR, INFO_STR, WARN_STR, ERROR_STR, DEBUG_STR, UNKNOWN_TYPE_STR};


#endif