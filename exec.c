#include "shell.h"

/**
 * execute_command - A system call that exexute the command line
 * @command: Pointer to a string
 * Return: Success.
 */
void execute_command(char *command)
{
	/* Fork a child process to execute the command */
	pid_t pid = fork();

	if (pid == -1)
		perror("fork"); /* Error occured while forking */
	else if (pid == 0)
	{
		/* Child process */
		char *args[MAX_COMMAND_LENGTH];
		char *token = strtok(command, " ");
		int i = 0;

		while (token != NULL && i < MAX_COMMAND_LENGTH - 1)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL; /* NULL-terminate the arguments array */
	/* Execute the command using execve */
	if (execve(args[0], args, NULL) == -1)
	{
		perror("execve"); /* Failed to exexute the command */
		exit(1);
	}
	/* Child process should not reach here unless execve fails */
	exit(0);
	}
	else
	{
		int status; /* Wait for the child process to complete */

		waitpid(pid, &status, 0);
	}
}
