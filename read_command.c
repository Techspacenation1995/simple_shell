#include "shell.h"

/**
 * read_command - A function that takes in input from a keyboard
 *
 * Return: Nothing
 */

char *read_command()
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t linelen = getline(&command, &bufsize, stdin);

	if (linelen == -1)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(command);
		return (NULL);
	}

	/* Remove the trailing newline character, if present */

	if (linelen > 0 && command[linelen - 1] == '\n')
	{
		command[linelen - 1] = '\0';
	}
	return (command);
}
