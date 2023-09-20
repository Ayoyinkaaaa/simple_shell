#ifndef SHELL_H
#define SHELL_H

/* Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#define MAX_ARGS 100
extern char **environ;

void parse_arguments(char *input, char *argv[]);
int main (void);
bool is_command_in_path(void);
void exec_comm(char *buffer, char *argv[]);
int command_exits(const char *buffer);
void env_func(void);
ssize_t get_line(char *buf, size_t nbytes);
#endif
