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
int main(void);
void exec_comm(char *buffer, char *argv[]);
int command_exits(const char *buffer);
void env_func(void);
ssize_t get_line(char *buf, size_t nbytes);

char *handle_path(char *comm);

int cdCommand(char *directory);

int iscdCommand(char *command);
int cdCommand(char *directory);
void exit_func(char *buffer, char *stat_num);

#endif
