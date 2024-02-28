#include "shell.h"
/**
* implement_cd - Change the current working directory.
* @command: array of strings of commands
* @argument:argv
* Return: 0.
*/
int implement_cd(char **command, char **argument)
{

	char *directory = command[1];
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("error in getcwd()");
		return (1);
	}
	if (directory == NULL || _strcmp(directory, "~") == 0)
		directory = _getenv("HOME");
	else if (_strcmp(directory, "-") == 0)
		directory = _getenv("OLDPWD");
	if (chdir(directory) == -1)
	{
		write(STDERR_FILENO, argument[0], _strlen(argument[0]));
		write(STDERR_FILENO, ": 1", 3);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, command[0], _strlen(command[0]));
		write(STDERR_FILENO, ": can't cd to ", 14);
		write(STDERR_FILENO, command[1], _strlen(command[1]));
		write(STDERR_FILENO, "\n", 1);
		return (1);
	}
	else
	{
		setenv("OLDPWD", cwd, 1);
		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			perror("error in getcwd()");
			return (1);
		}
	}
	return (0);
}
