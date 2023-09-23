#include "shell.h"

/**
 * is_comment - check if a line is a comment
 * @line:  input to check
 * Return: 1 or 0 othewise.
 */
int is_comment(const char *line)
{
	return (line[0] == '#');
}
