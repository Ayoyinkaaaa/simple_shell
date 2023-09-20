#include "shell.h"
#include <sys/stat.h>

/**
 * get_location - function that handles path
 *
 * @command: command to check for
 * Return: A pointer to a dynamically allocated string containing the
 * full path to the command if found, or NULL if not found or on error.
 */
char *get_location(char *command)
{
	char *path;  char *result;
	path = getenv("PATH");

	if (!path)
	{
		return (NULL);
	}

	result = NULL;

	if (!result)
	{
		struct stat buffer;

		if (stat(command, &buffer) == 0)
		{
		}
	}
	else
	{

	}
		free(result);
		return (result);
}

/**
 * search_in_directory - search for command in a specific directory
 * @directory: search
 * @command: the command t search for.
 *
 * Return: A pointer to a dynamically allocated string containing the
 * full path to the command if found, or NULL if not found or on error.
 */
char *search_in_directory(const char *directory, const char *command)
{
	 int command_length = strlen(command);
	 int directory_length = strlen(directory);
	char *file_path = (char *) malloc(command_length + directory_length + 2);
	char *path_token = NULL;
	struct stat buffer;

	if (!file_path)
	{
		return (NULL);
	}

	strcpy(file_path, path_token);
	strcat(file_path, "/");
	strcat(file_path, command);


	if (stat(file_path, &buffer) == 0)
	{
		return (file_path);
	}

	free(file_path);
	return (NULL);
}

/**
 * search_in_path - Search for a command in the system's PATH.
 * @path: The system's PATH variable.
 * @command: The command to search for.
 *
 * Return: A pointer to a dynamically allocated string containing the
 * full path to the command if found, or NULL if not found or on error.
 */
char *search_in_path(const char *path, const char *command)
{
	char *path_copy; char *path_token; char *result;

	path_copy = strdup(path);

	if (!path_copy)
	{
		return (NULL);
	}

	path_token = strtok(path_copy, ":");
	result = NULL;

	while (path_token != NULL)
	{
		result = search_in_directory(path_token, command);

		if (result)
		{
			break;
		}
		path_token = strtok(NULL, ":");
	}

	free(path_copy);
	return (result);
}
