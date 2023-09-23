#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

int command_exists(const char *buffer)

/**
 * non_interactive - print command in a non interactive mode
 */
void non_interactive(void)
{
	char *buffer = "/bin/ls";

	char *argv[] = {buffer, NULL};
	int input_fd = STDIN_FILENO;
	int output_fd = STDOUT_FILENO;
	int stat;
	pid_t child;

	if
		(command_exists(buffer) != 0)
	{
		write(STDOUT_FILENO, "command does not exist\n", 24);
		return;
	}

	child = fork();

	if (child == -1)
	{
		perror("Error:");
		return;
	}

	if (child == 0)
	{
		dup2(input_fd, STDIN_FILENO);
		dup2(output_fd, STDOUT_FILENO);

		if (execve(buffer, argv, NULL) == -1)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&stat);
	}
}
