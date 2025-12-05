#ifndef FUNCS_H
#define FUNCS_H

#include <stdlib.h>

#define BUFF_SIZE 1024

void get_timestamp(char *buff, size_t n);
void log_action(const char *fmt, ...);
void create_file();
void append_file();
void read_file();

#endif // FUNCS_H
