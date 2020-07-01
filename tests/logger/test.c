#include <stdio.h>
#include <time.h>

#ifndef LOG_DEBUG_
    #define LOG_DEBUG_
#endif

#include "logger.h"

int main (int argc, char **argv)
{
    printf("\n");

    printf("Given FilePath (Argv[1]) :\n\tPointer : %p\n\tString : %s\n", argv[1], argv[1]);

    printf("\n");

    printf("Creating logger...\n");
    logger_t *logger = create_logger(true, true, argv[1], true);
    printf("Logger created\n");

    printf("\n");

    printf("Logger : %p\n", logger);
    printf("FD : %d\n", logger->fd);
    printf("Std_Output : %d\n", logger->std_output);
    printf("Message : %p\n\t%s\n", logger->msg, logger->msg);

    printf("\n");

    log_msg(logger, NONE, asprintf(&logger->msg, "Test None\n"));
    log_msg(logger, INFO, asprintf(&logger->msg, "Test Info\n"));
    log_msg(logger, WARN, asprintf(&logger->msg, "Test Warn\n"));
    log_msg(logger, ERROR, asprintf(&logger->msg, "Test Error\n"));
    log_msg(logger, DEBUG, asprintf(&logger->msg, "Test Debug (Alone)\n"));

    printf("\n");

    log_msg(logger, DEBUG | NONE, asprintf(&logger->msg, "Test Debug (None)\n"));
    log_msg(logger, DEBUG | INFO, asprintf(&logger->msg, "Test Debug (Info)\n"));
    log_msg(logger, DEBUG | WARN, asprintf(&logger->msg, "Test Debug (Warn)\n"));
    log_msg(logger, DEBUG | ERROR, asprintf(&logger->msg, "Test Debug (Error)\n"));
    log_msg(logger, DEBUG | DEBUG, asprintf(&logger->msg, "Test Debug (Debug)\n"));

    printf("\n");

    printf("Deleting logger...\n");
    delete_logger(logger);
    printf("Logger deleted\n");

    printf("\n");

    return (0);
}