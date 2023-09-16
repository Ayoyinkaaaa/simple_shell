#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

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

int main()
{
	while (1)
	{
	char *buffer, *argv[MAX_ARGS];
	size_t BUFF_SIZE = 1024;
	ssize_t c;
	int stat;
	pid_t child;

	buffer = malloc(sizeof(char) * BUFF_SIZE);
	if (buffer == NULL)
	{
		perror("Error allocating memory:");
		return (1);
	}
	write(STDOUT_FILENO, "#simpleshell$ ", 14);
	c = getline(&buffer, &BUFF_SIZE, stdin);
	if (c == -1)
	{
		if (feof(stdin))
		{
			free(buffer);
			break;
		}
		else
		{
			perror("Error reading input:");
			free(buffer);
			return(1);
		}
	}
	buffer[c - 1] = '\0';
	parse_arguments(buffer, argv);
	child = fork();
	if (child == -1)
	{
		perror("Error:");
		free(buffer);
		return (1);
	}
	if (child == 0)
	{
		if (execve(buffer, argv, NULL) == -1)
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
	free(buffer);
	}
	write(STDOUT_FILENO, "\n", 2);
	return (0);
}
