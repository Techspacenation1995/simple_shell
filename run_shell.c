#include "shell.h"

/**
 * run_shell - Function that its parent calls the child process.
 * @env: A double pointer that points to the environment path
 *
 * Return: Nothing.
 */

void run_shell(char **env)
{
	char *cmd;
	int status;
	pid_t pid = fork();

	while (1)
	{
		display_prompt();
		cmd = read_command();
		if (cmd == NULL)
		{
			break;
		}

		if (pid == -1)
		{
			perror("fork failed");
		}
		else if (pid == 0)
		{
			execute_command(cmd, env);
			exit(1);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
		free(cmd);
	}
}
