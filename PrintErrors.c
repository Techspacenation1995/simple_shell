#include"shell.h"
/**
 * printErro - Prints an error message to the standard error stream.
 * @shell_name: The name of the shell program.
 * @count: The command count.
 * @command_array: The command or argument causing the error.
 * @type_of_error: The type of error.
 * Return: nothing
 */

void printError(char *shell_name, int count,
char *command_array, int type_of_error)
{
	char *countString;

	countString = convertNum2char(count);

	write(STDERR_FILENO, shell_name, _strlen(shell_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, countString, _strlen(countString));
	write(STDERR_FILENO, ": ", 2);

	if (type_of_error == EXIT_ERROR)
	{
		write(STDERR_FILENO, "unknown number: ", 16);
		write(STDERR_FILENO, command_array, _strlen(command_array));
		write(STDERR_FILENO, "\n", 1);
	}
	else if (type_of_error == NOT_FOUND)
	{
		write(STDERR_FILENO, "not found\n", 10);
	}
	else if (type_of_error == PERMISSION_DENIED)
	{
		write(STDERR_FILENO, "Permission denied\n", 18);
	}

	free(countString);
}
