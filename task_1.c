#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
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
	char *buffer, *argv[] = {NULL};
	size_t buff_size = 1024, c;
	int stat;
	pid_t child;

	buffer = malloc(sizeof(char) * buff_size);
	if (buffer == NULL)
	{
		perror("Error allocating memory:");
		return (1);
	}
	write(STDOUT_FILENO, "#command$ ", 10);
	c = getline(&buffer, &buff_size, stdin);
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
	child = fork();
	if (child == -1)
	{
		perror("Error:");
		free(buffer);
		return (1);
	}
	if (child == 0)
	{
		argv[0] = buffer;
		argv[1] = NULL;
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
