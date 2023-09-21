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
	int exit_stat;

	if (stat_num == NULL)
	{
		free(buffer);
		exit(0);
	}
	else
	{
		exit_stat = atoi(stat_num);
		if (exit_stat == 0)
		{
			exit(exit_stat);
			perror("Error");
			free(buffer);
		}
		if (exit_stat < 0)
		{
			exit(exit_stat);
			perror("Error");
			free(buffer);
		}
		free(buffer);
		exit(exit_stat);
	}
}
