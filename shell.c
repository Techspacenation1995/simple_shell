#include "shell.h"
/**
* main - Function that run SHELL program
* @argc: Argument Count.
* @argv: Argument vector
* @env: The shell environment
* Return: Exit status of the program
*/
int main(int argc, char *argv[], char *env[])
{
	int *status, count = 0, non_interactive = 1, s = 0, op_mode;
	char *command, **command_lines, **cmd_arr = NULL;
	list_paths *current;

	status = &s;
	op_mode = mode(argc);
	if (op_mode != INTERACTIVE_MODE)
		command_lines = scanCommands(op_mode, argv[1], argv[0]);
	current = tokenised();
	while (non_interactive && ++count)
	{
		if (op_mode == NON_INTERACTIVE_MODE || op_mode == NON_INTERACTIVE_PIPE)
		{
			if (command_lines[count - 1])
				command = command_lines[count - 1];
			else
			{
				free(command_lines);
				break;
			}
		}
		else if (op_mode == INTERACTIVE_MODE)
			command = _getline(current);
		if (!command)
			continue;
		cmd_arr = Handle_arrays(command, *status);
		if (!cmd_arr)
		{
			free(command);
			continue;
		}
		if (checkdir(cmd_arr[0], argv, count, cmd_arr, status, command) == 0)
			continue;
		if (builtInCommands(command, cmd_arr, current, argv[0],
			count, status, NULL, command_lines, argv) != 0)
			nonbuiltin_handler(cmd_arr, env, status, count, current, argv);
		free_allocated(command, cmd_arr);
	}
	freeList(current);
	exit(*status);
}
