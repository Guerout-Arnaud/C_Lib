#include <stdio.h>
#include <time.h>

#ifndef LOG_DEBUG_
    #define LOG_DEBUG_
#endif

#include "logger.h"

extern logger_t logger;

void *logger_thread(void *arg)
{
    (void) arg;
    log_msg(LOG_INFO, "logger_thread()\n");
    return (NULL);
}

int main (int argc, char **argv)
{
    printf("\n");

    printf("Given FilePath (Argv[1]) :\n\tPointer : %p\n\tString : %s\n", argv[1], argv[1]);

    printf("\n");

    printf("Creating logger...\n");
    if (logger_init(true, true, true) != 0) {
        printf("ERROR: Logger not created\n");
        return (-1);
    }
    printf("Logger created\n");

    printf("\n");

    printf("Adding file to logger...\n");
    if (logger_add_filename(argv[1]) != 0) {
        printf("ERROR: File not added\n");
        return (-1);
    }
    printf("File added to logger\n");

    // logger_t *logger = create_logger(true, true, argv[1], true);

    printf("\n");

    printf("FDs: [");
    for (int i = 0; i < logger.fds_len; i++) {
        if (logger.fds[i] == stdout) {
            printf("stdout");
        } else {
            printf("%d", fileno(logger.fds[i]));
        }
        if (i != logger.fds_len - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    printf("\n");

    printf("Threads...\n");
    pthread_t thread = 0;

    pthread_create(&thread, NULL, logger_thread, NULL);

    log_msg(LOG_INFO, "main()\n");

    pthread_join(thread, NULL);
    printf("Joined\n");

    printf("\n");

    log_msg(LOG_NONE, "Test None\n");
    log_msg(LOG_INFO, "Test Info\n");
    log_msg(LOG_WARN, "Test Warn\n");
    log_msg(LOG_ERROR, "Test Error\n");
    log_msg(LOG_DEBUG, "Test Debug (Alone)\n");

    printf("\n");

    log_msg(LOG_DEBUG | LOG_NONE, "Test Debug (None)\n");
    log_msg(LOG_DEBUG | LOG_INFO, "Test Debug (Info)\n");
    log_msg(LOG_DEBUG | LOG_WARN, "Test Debug (Warn)\n");
    log_msg(LOG_DEBUG | LOG_ERROR, "Test Debug (Error)\n");
    log_msg(LOG_DEBUG | LOG_DEBUG, "Test Debug (Debug)\n");

    printf("\n");

    printf("Deleting logger...\n");
    logger_destroy();
    printf("Logger deleted\n");

    printf("\n");

    printf("Done\n");
    return (0);
}