#include"shell.h"
/**
* free_allocated - Free allocated memory
* @command: Pointer to the command string
* @command_array: Pointer to the array of command and its arguments
* This function frees the memory allocated.
* command and its arguments.
*/
void free_allocated(char *command, char **command_array)
{
	free(command);
	free_array(command_array);
}
