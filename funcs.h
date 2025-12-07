#ifndef FUNCS_H
#define FUNCS_H

#include <stdlib.h>

// Consts
#define BUFF_SIZE 1024

// Utils
void get_timestamp(char *buff, size_t n);
void log_action(const char *fmt, ...);

// Operations
void op(const char *mode, const char *action);

#endif // FUNCS_H
