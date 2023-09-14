#include "shell.h"

/**
 * parse_arguments - tokenize a string into an array of arguments
 * @input: string to be tokenized.
 * @argv: an array to store parsed arguments.
 */
void parse_arguments(char *input, char *argv[])
{
	int arg count = 0;
	char *token = strtok(input, " ");

	while (token != NULL && arg_count < MAX_ARGS - 1)
	{
		argv[arg_count] = token;
		arg_count++;
		token = strtok(NULL, " ");
	}
	argv[arg_count] = NULL;
}

/**
 * main - Entry point.
 *
 * This function implements that prompt the user for commands
 * parses them and execute them in child processes
 * Return: 0
 */

int main(void)
{
	char input[BUFF_SIZE];
	char *argv[MAX_ARGS];

	while (1)
	{
		write(STDOUT_FILENO, "simpleshell> ", 13);

		fgets(input, sizeof(input), stdin);

		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)
		{
			break;
		}

		parse_arguments(input, argv);

		pid_t pid = fork();

		if
			(pid == -1);
		{
		perror("fork");
		}
		else if
			(pid == 0);
		{
			execvp(argv[0], argv);
			perror("exec");
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;

			waitpid(pid, &status, 0);
		}
	}
	return (0);
}
