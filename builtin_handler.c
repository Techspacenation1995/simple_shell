#include "shell.h"

/**
 * builtin_handler - Handles built-in commands.
 * @command: The original command entered by the user.
 * @command_array: An array of strings containing the parsed command.
 * @current: A pointer to a list_paths struct representing the current path.
 * @shell_name: The name of the shell.
 * @count: The count of the commands entered in the shell.
 * @status: A pointer to an integer variable to set the status.
 * @env_list: environment variable.
 * @argv: string variable.
 * @command_lines: command line argument..
 *
 * Return: The function returns 0 on successful execution of a built-in command
 * -1 if the command is not a built-in command
 */
int builtin_handler(char *command, char **command_array, list_paths *current,
char *shell_name, int count, int *status,
list_paths *env_list, char **command_lines, char **argv)
{
	int i, n;
	char *built_in[] = {"env", "exit", "cd", "setenv"};

	n = -1;

	for (i = 0; i < 4; i++)
	{
		if (_strcmp(built_in[i], command_array[0]) == 0)
		{
			n = i;
			break;
		}
	}

	if (n == -1)
		return (n);

	switch (n)
	{
		case 0:
			print_env(status);
			break;
		case 1:
			exit_handler(command, command_array,
			current, shell_name, count, status, env_list, command_lines);
			break;
		case 2:
			implement_cd(command_array, argv);
			break;
		case 3:
			implement_setenv(command_array[1], command_array[2], current);
			break;
		default:
			return (-1);
	}
	return (0);
}
