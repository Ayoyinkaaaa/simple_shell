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

#define MAX_ARGS 100
#define BUFF_SIZE 1024


void parse_arguments(char *input, char *argv[]);
int main (void);
#endif
