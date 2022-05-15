#include <stdio.h>

#include "logger.h"

int main (int argc, char **argv)
{
    logger_init(true, false, true);

    log_msg(LOG_NONE, "Your Log Message Here (Log Type NONE)\n");
    log_msg(LOG_INFO, "Your Log Message Here (Log Type INFO)\n");
    log_msg(LOG_WARN, "Your Log Message Here (Log Type WARN)\n");
    log_msg(LOG_ERROR, "Your Log Message Here (Log Type ERROR)\n");
    log_msg(LOG_DEBUG, "Your Log Message Here (Log Type DEBUG + Nothing)\n");

    printf("\n");

    log_msg(LOG_DEBUG | LOG_NONE, "Your Log Message Here (Log Type DEBUG + NONE)\n");
    log_msg(LOG_DEBUG | LOG_INFO, "Your Log Message Here (Log Type DEBUG + INFO)\n");
    log_msg(LOG_DEBUG | LOG_WARN, "Your Log Message Here (Log Type DEBUG + WARN)\n");
    log_msg(LOG_DEBUG | LOG_ERROR, "Your Log Message Here (Log Type DEBUG + ERROR)\n");
    log_msg(LOG_DEBUG | LOG_DEBUG, "Your Log Message Here (Log Type DEBUG + DEBUG)\n");

    logger_destroy();
    return (0);
}