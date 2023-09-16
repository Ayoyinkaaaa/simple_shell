#include "shell.h"

/**
 * is_command_in_path - checks if a command is in the system's path.
 *
 * Description: This function takes a command as input and checks if it exists
 * in the system's PATH.
 * Return: True if command is in path, or false.
 */
bool is_command_in_path(void)
{
	const char *command = "ls";
	char *path = getenv("PATH");
	char *token;

	if (path == NULL)
	{
		return (false);
	}

	token = strtok(path, ":");

	while (token != NULL)
	{

		char full_path[1024];

		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			return (true);
		}

		token = strtok(NULL, ":");
	}
	return (false);
}
