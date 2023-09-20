#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "shell.h"

/**
 * handle_path - main
 *
 * @comm: input
 *
 * Return: path
 *
 */

char *handle_path(char *comm)
{
	int comm_len, path_len;
	struct stat buf;
	char *path, *copy, *tokens, *file;

	path = getenv("PATH");
	if (path)
	{
		comm_len = strlen(comm);
		copy = strdup(path);
		if (copy == NULL)
			return (NULL);
		tokens = strtok(copy, ":");
		while (tokens != NULL)
		{
			path_len = strlen(tokens);
			file = malloc(comm_len + path_len + 2);
			if (file == NULL)
				return (NULL);
			strcpy(file, tokens);
			strcat(file, "/");
			strcat(file, comm);
			strcat(file, "\0");
			if (stat(file, &buf) == 0)
			{
				free(copy);
				return (file);
			}
			else
			{
				free(file);
				tokens = strtok(NULL, ":");
			}
		}
		free(copy);
		if (stat(comm, &buf) == 0)
			return (comm);
		return (NULL);
	}
	return (NULL);
}
