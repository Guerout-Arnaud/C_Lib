#include <stdio.h>

#include "logger.h"

int main (int argc, char **argv)
{
    logger_t *logger = create_logger(true, false, argv[1], true);

    log_msg(logger, LOG_NONE, asprintf(&logger->msg, "Your Log Message Here (Log Type NONE)\n"));
    log_msg(logger, LOG_INFO, asprintf(&logger->msg, "Your Log Message Here (Log Type INFO)\n"));
    log_msg(logger, LOG_WARN, asprintf(&logger->msg, "Your Log Message Here (Log Type WARN)\n"));
    log_msg(logger, LOG_ERROR, asprintf(&logger->msg, "Your Log Message Here (Log Type ERROR)\n"));
    log_msg(logger, LOG_DEBUG, asprintf(&logger->msg, "Your Log Message Here (Log Type DEBUG + Nothing)\n"));

    printf("\n");

    log_msg(logger, LOG_DEBUG | LOG_NONE, asprintf(&logger->msg, "Your Log Message Here (Log Type DEBUG + NONE)\n"));
    log_msg(logger, LOG_DEBUG | LOG_INFO, asprintf(&logger->msg, "Your Log Message Here (Log Type DEBUG + INFO)\n"));
    log_msg(logger, LOG_DEBUG | LOG_WARN, asprintf(&logger->msg, "Your Log Message Here (Log Type DEBUG + WARN)\n"));
    log_msg(logger, LOG_DEBUG | LOG_ERROR, asprintf(&logger->msg, "Your Log Message Here (Log Type DEBUG + ERROR)\n"));
    log_msg(logger, LOG_DEBUG | LOG_DEBUG, asprintf(&logger->msg, "Your Log Message Here (Log Type DEBUG + DEBUG)\n"));

    printf("\n");

    delete_logger(logger);
    return (0);
}