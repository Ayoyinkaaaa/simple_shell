#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * exit_func - main
 *
 * @buffer: input
 *
 * @stat_num: input
 *
 */

void exit_func(char *buffer, char *stat_num)
{
	int exit_stat = 0;

	if (stat_num != NULL)
	{
		exit_stat = atoi(stat_num);
	}

	free(buffer);
	exit(exit_stat);
}
