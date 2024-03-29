#include"shell.h"
/**
 * is_exit - Checks if the command is an "exit" command and handles it.
 * @command: The original command entered by the user.
 * @command_array: An array of strings containing the command and its arguments
 * @current: A pointer to a list_paths struct representing the current path.
 * @shell_name: The name of the shell program.
 * @count: The command count.
 * @status: A pointer to an integer variable representing the status.
 * @command_lines:.
 * @env:.
 * Return:Nothing
 */

void is_exit(char *command, char **command_array, list_paths *current,
char *shell_name, int count, int *status,
list_paths *env, char **command_lines)
{
	int exit_num;

	if (_strcmp(command_array[0], "exit") == 0)
	{
		if (command_array[1] == NULL)
		{
			free_whole(command_lines, count, env,
			current, command, command_array);
			exit(*status);
		}
		else if (command_array[1] != NULL)
		{
			if (_strlen(command_array[1]) <= 9)
			{
				exit_num = _conv_string(command_array[1]);
				if (exit_num != -1)
				{
					free_whole(command_lines, count, env,
					current, command, command_array);
					exit(exit_num);
				}
				else
				{
					*status = EXIT_ERROR;
					printError(shell_name, count, command_array[1], EXIT_ERROR);
				}
			}
			else
			{
				*status = EXIT_ERROR;
				printError(shell_name, count, command_array[1], EXIT_ERROR);
			}
		}
	}
}
/**
 * free_whole - free whole
 * @command: The original command entered by the user.
 * @command_array: An array of strings containing the command and its arguments
 * @current: A pointer to a list_paths struct representing the current path.
 * @count: The command count.
 * @command_lines:.
 * @env: environmental variables
 * Return: Nothing
*/
void free_whole(char **command_lines, int count, list_paths *env,
		list_paths *current, char *command, char **command_array)
{
	if (command_lines)
	{
		free(command_lines[count]);
		if (command_lines)
			free(command_lines);
	}
	freeList(env);
	freeList(current);
	free_allocated(command, command_array);
}
