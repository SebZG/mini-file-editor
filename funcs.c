#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "funcs.h"

void get_timestamp(char *buff, size_t n)
{
    time_t t = time(NULL);
    struct tm *lt = localtime(&t);
    strftime(buff, n, "[%Y-%m-%d %H:%M:%S]", lt);
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

void create_file()
{
    char *filename = malloc(BUFF_SIZE);
    if (!filename)
    {
        perror("malloc");
        return;
    }

    printf("Enter new filename: ");
    if (!fgets(filename, BUFF_SIZE, stdin))
    {
        free(filename);
        return;
    }
    filename[strcspn(filename, "\n")] = 0;

    FILE *f = fopen(filename, "w");
    if (!f)
    {
        perror("fopen");
        free(filename);
        return;
    }
    log_action("Created file '%s'", filename);

    printf("Enter text (end with a single dot on a line):\n");
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, stdin) > 0)
    {
        if (strcmp(line, ".\n") == 0)
            break;
        fputs(line, f);
    }

    free(line);
    fclose(f);
    free(filename);
}
