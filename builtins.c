#include "shell.h"


/**
 * iscdCommand - check if the command is "cd"
 * @command: command to check
 * This function checks if the provided command is "cd"
 * Return: 1 if the command is "cd", 0 otherwise.
 */
int iscdCommand(char *command)
{
	return (strcmp(command, "cd") == 0);
}

/**
 * cdCommand - Execute the cd command.
 * @directory: directory to change.
 *
 * Return: 1 if successful and 0 if otherwise.
 */
int cdCommand(char *directory)
{
	char *previousDirectory = NULL;

	if (directory == NULL)
	{
		directory = getenv("HOME");
	}
	else if (strcmp(directory, "-") == 0)
	{
		if (previousDirectory != NULL)
		{
			directory = previousDirectory;
		}
		else
		{
			return (0);
		}
	}

	if (chdir(directory) == 0)
	{
		setenv("PWD", directory, 1);
		return (1);
	}
	else
	{
		return (0);
	}
}
