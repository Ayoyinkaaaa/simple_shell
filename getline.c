#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * get_line - main
 *
 * @buf: input
 *
 * Return: output
 *
 */

ssize_t get_line(char *buf, size_t nbytes)
{
	ssize_t bytes_read;
	bytes_read = read(STDIN_FILENO, buf, nbytes);
	return(bytes_read);
}
