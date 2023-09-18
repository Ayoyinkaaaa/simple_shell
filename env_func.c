#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

void env_func(void)
{
	int i;

	for (i = 0 ;  environ[i] != NULL ; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 2);
	}
}
