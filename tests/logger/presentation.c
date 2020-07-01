#include <stdio.h>

#include "logger.h"

int main (int argc, char **argv)
{
    logger_t *logger = create_logger(true, false, argv[1], true);

    log_msg(logger, NONE, asprintf(&logger->msg, "Your Log Message Here (Log Type NONE)\n"));
    log_msg(logger, INFO, asprintf(&logger->msg, "Your Log Message Here (Log Type INFO)\n"));
    log_msg(logger, WARN, asprintf(&logger->msg, "Your Log Message Here (Log Type WARN)\n"));
    log_msg(logger, ERROR, asprintf(&logger->msg, "Your Log Message Here (Log Type ERROR)\n"));
    log_msg(logger, DEBUG, asprintf(&logger->msg, "Your Log Message Here (Log Type DEBUG + Nothing)\n"));

    printf("\n");

    log_msg(logger, DEBUG | NONE, asprintf(&logger->msg, "Your Log Message Here (Log Type DEBUG + NONE)\n"));
    log_msg(logger, DEBUG | INFO, asprintf(&logger->msg, "Your Log Message Here (Log Type DEBUG + INFO)\n"));
    log_msg(logger, DEBUG | WARN, asprintf(&logger->msg, "Your Log Message Here (Log Type DEBUG + WARN)\n"));
    log_msg(logger, DEBUG | ERROR, asprintf(&logger->msg, "Your Log Message Here (Log Type DEBUG + ERROR)\n"));
    log_msg(logger, DEBUG | DEBUG, asprintf(&logger->msg, "Your Log Message Here (Log Type DEBUG + DEBUG)\n"));

    printf("\n");

    delete_logger(logger);
    return (0);
}