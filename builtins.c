#include "shell.h"
#include "limits.h"
/**
 * cdCommand - Execute the cd command.
 * @directory: directory to change.
 * Return: 1 if successful and 0 if otherwise.
 */
int cdCommand(char *directory)
{
	char previousDirectory[PATH_MAX];
	char currentDirectory[PATH_MAX];

	if (getcwd(currentDirectory, sizeof(previousDirectory)) == NULL)
	{
		perror("getcwd");
		return (0);
	}
	if (directory == NULL || *directory  == '\0')
	{
		directory = getenv("HOME");
	}
	else if (strcmp(directory, "-") == 0)
	{
		if (previousDirectory != NULL)
		{
			directory = (char *)previousDirectory;
		}
		else
		{
			write(STDERR_FILENO, "cd: No previous directory stored.\n",
			strlen("cd: No previous directory stored.\n"));
			return (0);
		}
	}
	if (chdir(directory) == 0)
	{
		if (setenv("PWD", directory, 1) == -1)
		{
			perror("setenv");
			return (0);
		}
		return (1);
	}
	else
	{
		perror("chdir");
		return (0);
	}
}
