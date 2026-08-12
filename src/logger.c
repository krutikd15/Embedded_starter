#include <stdio.h>
#include <time.h>

#include "logger.h"

static FILE *log_file = NULL;

static void write_log(const char *level, const char *message)
{
    time_t now;
    struct tm *time_info;
    char time_string[20];

    if (log_file == NULL)
    {
        return;
    }

    time(&now);

    time_info = localtime(&now);

    strftime(
        time_string,
        sizeof(time_string),
        "%H:%M:%S",
        time_info
    );

    fprintf(
        log_file,
        "%s %-5s %s\n",
        time_string,
        level,
        message
    );

    fflush(log_file);
}

int logger_init(void)
{
    log_file = fopen("logs/device.log", "w");

    if (log_file == NULL)
    {
        return -1;
    }

    return 0;
}

void log_info(const char *message)
{
    write_log("INFO", message);
}

void log_debug(const char *message)
{
    write_log("DEBUG", message);
}

void log_warning(const char *message)
{
    write_log("WARN", message);
}

void log_error(const char *message)
{
    write_log("ERROR", message);
}

void logger_close(void)
{
    if (log_file != NULL)
    {
        fclose(log_file);
        log_file = NULL;
    }
}