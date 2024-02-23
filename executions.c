#include "shell.h"

/**
* executions - a function to execute built in  commands.
* @string: argument vector containing the command and it argumments
*
* Return: 0 if the command is an in_built command and successfully executed.
*         and -1 if not a built in command
*/


int executions(char **string)
{
	command functions[] = {
		{"cd", &exec_cd_dir},
		{"env", &exec_env},
		{"exit", &exec_exit},
		{NULL, NULL}
	};

unsigned int i = 0;

if (string[0] == NULL)
	return (-1);

while (functions[i].name != NULL)
{
	if (strcmp(string[0], functions[i].name) == 0)
		return (functions[i].funct(string));
	i++;
}

	return (execute(string));
}
