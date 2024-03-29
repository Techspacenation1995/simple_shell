#include "shell.h"

/**
 * scanCommands - Scans command files based on the operation mode.
 * @op_mode: The operation mode.
 * @file_name: The name of the command file.
 * @shell_name: The name of the shell program.
 * Return: The array of command lines read from the file.
 */
char **scanCommands(int op_mode, char *file_name, char *shell_name)
{
	char **command_lines;

	if (op_mode == NON_INTERACTIVE_PIPE)
	{
		command_lines = pipes_handler();
		if (!command_lines)
			exit(0);
	}
	else if (op_mode == NON_INTERACTIVE_MODE)
	{
		command_lines = handle_non_interactivefile(file_name, shell_name);
		if (!command_lines)
			exit(0);
	}
	return (command_lines);
}
