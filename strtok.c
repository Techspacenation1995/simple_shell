#include "shell.h"

/**
 * find_executable- A function that determines the excutable part.
 * @cmd: A pointer to a string.
 *
 * Return: Executable.
 */

char *find_executable(char *cmd)
{
	char *delim = " ";
	char *token;

	token = strtok(cmd, delim);

	return (token);
}
