#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * command_exists - main
 *
 * @buffer: input
 *
 * Return: output
 *
 */
int command_exists(const char *buffer)
{
	return (access(buffer, X_OK));
}

/**
 * exec_comm - main
 *
 * @buffer: input
 *
 * @argv: input
 *
 */
void exec_comm(char *buffer, char *argv[])
{
	int stat;
	pid_t child;
	char *envp[] = {"PATH=/bin:/usr/bin", "HOME=/home/user", NULL};

	if (strcmp(buffer, "env") == 0)
	{
		env_func();
		return;
	}
	if (command_exists(buffer) != 0)
	{
		write(STDOUT_FILENO, "Command does not exist\n", 24);
		return;
	}
	child = fork();
	if (child == -1)
	{
		perror("Error:");
		free(buffer);
		return;
	}
	if (child == 0)
	{
		if (execve(buffer, argv, envp) == -1)
		{
			perror("Error:");
			free(buffer);
			exit(1);
		}
	}
	else
	{
		waitpid(child, &stat, 0);
	}
}

/**
 * parse_arguments - main
 *
 * @input: input
 *
 * @argv: input
 *
 */
void parse_arguments(char *input, char *argv[])
{
	int arg_count = 0;
	char *token;

	token = strtok(input, " ");
	while (token != NULL && arg_count < MAX_ARGS - 1)
	{
		argv[arg_count] = token;
		arg_count++;
		token = strtok(NULL, " ");
	}
	argv[arg_count] = NULL;
}

/**
 * main - main
 *
 * Return: Always Success
 *
 */

int main(void)
{
	while (1)
	{
	char *buffer, *argv[MAX_ARGS];
	size_t BUFF_SIZE = 1024;
	ssize_t c;

	buffer = malloc(sizeof(char) * BUFF_SIZE);
	if (buffer == NULL)
	{
		perror("Error allocating memory:");
		return (1);
	}
		write(STDOUT_FILENO, "$ ", 2);
		c = getline(&buffer, &BUFF_SIZE, stdin);
		if (c == -1)
		{
			if (feof(stdin))
			{
				free(buffer);
				write(STDOUT_FILENO, "\n", 2);
				break;
			}
			else
			{
				perror("Error reading input:");
				free(buffer);
				return (1);
			}
		}
	buffer[c - 1] = '\0';
	if (strcmp(buffer, "exit") == 0)
	{
		free(buffer);
		break;
	}
	parse_arguments(buffer, argv);
	exec_comm(buffer, argv);
	free(buffer);
	}
	return (0);
}
