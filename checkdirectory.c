#include"shell.h"
/**
* checkdir - checks if a directory exists and accessible
* @command: the name of the directory to check
* @argument_vector: arguement vectors
* @count: count of arguements
* @command_array: an array of commands
* @status: status value variable
* @command_line_before: previous command is....
* Return: 1 if the directory exists and is accessible, else 0
*/
int checkdir(char *command, char **argument_vector, int count,
char **command_array, int *status, char *command_line_before)
{
	struct stat st;

if (stat(command, &st) == 0)
{
	if (S_ISDIR(st.st_mode))
	{
		printError(argument_vector[0], count, command_array[0], PERMISSION_DENIED);
		*status = PERMISSION_DENIED;
		free_allocated(command_line_before, command_array);
		return (0);
	}
}
return (-1);
}
