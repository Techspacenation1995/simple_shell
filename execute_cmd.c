#include "shell.h"

/**
 * execute_command - Implementing a function that executes a command
 * @cmd: A pointer to the string that reperent the command
 * @env: A double pointer that reprent the path.
 *
 * Return: Void
 */

void execute_command(char *cmd, char **env)
{
	char *exe = find_executable(cmd);

	if (_strcmp(exe, "exit") == 0)
	{
		exit(0);
	}
	else if (_strcmp(exe, "env") == 0)
	{
		char **env_var = env;

		while (*env_var)
		{
			write(STDOUT_FILENO, *env_var, _strlen(*env_var));
			write(STDOUT_FILENO, "\n", 1);
			env_var++;
		}
	}
	else
	{
		char *path = env[0]; /* the first ele. of env is usually the PATH var */
		char *dir = strtok(path, ":");

		while (dir != NULL)
		{
			char exe_path[MAX_COMMAND_LENGTH];

			_strcpy(exe_path, dir);
			_strcat(exe_path, "/");
			_strcat(exe_path, exe);

			char *args[] = {exe, NULL}; /* Command and argument array for execve */

			if (execve(exe_path, args, env) != -1)
			{
				return;
			}
			dir = strtok(NULL, ":");
		}
		perror("execve");
	}
}
