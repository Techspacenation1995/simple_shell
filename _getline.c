#include"shell.h"
/**
 * _getline - implements the getline function
 *
 *
 * @current: A pointer to a list_paths struct representing the current path.
 *
 * Return: command after scanning.
 */

char *_getline(list_paths *current)
{
	ssize_t read;
	size_t s = 0;
	char *command = NULL;

	write(STDOUT_FILENO, "($) ", 4);
	read = getline(&command, &s, stdin);
	if (read == EOF)
	{
		write(STDOUT_FILENO, "\n", 1);
		freeList(current);
		free(command);
		exit(0);
	}
	if (read == 1 && command[0] == '\n')
	{
		free(command);
		return (NULL);
	}

	command[read - 1] = '\0';

	return (command);
}
