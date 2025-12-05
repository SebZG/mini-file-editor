#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "funcs.h"

static void get_timestamp(char *buff, size_t n)
{
    time_t t = time(NULL);
    struct tm *lt = localtime(&t);
    strftime(buff, n, "[%Y-$%m-%d %H:%M:%S]", lt);
}


void log_action(const char *fmt, ...)
{
    char timebuff[32];
    get_timestamp(timebuff, sizeof(timebuff));

    printf("%s ", timebuff);

    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);

    putchar('\n');
}
