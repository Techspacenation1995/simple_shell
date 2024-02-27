#include "shell.h"

/**
 * execute - A function that executes a command.
 * @av: argument it takes
 *
 * Return: (-1)
 */

int execute(char *av[])
{
	pid_t forkRV;
	int status;

	if (av == NULL || av[0] == NULL || av[0][0] == '\0')
	{
		write(STDERR_FILENO, "Invalid command.\n", 17);
		return (-1);
	}

	forkRV = fork();
	if (forkRV < 0)
	{
		perror("Fork failed");
		return (-1);
	}

	if (forkRV == 0)
	{
		char *full_path = "/bin/";  // You need to provide the correct path to the executable
		char *full_command = malloc(strlen(full_path) + strlen(av[0]) + 1);
		if (full_command == NULL)
		{
			perror("Error");
			free_tokens(av);
			exit(EXIT_FAILURE);
		}

		strcpy(full_command, full_path);
		strcat(full_command, av[0]);

		char *envp[] = {"VAR=value", NULL};  // Example environment variable

		if (execve(full_command, av, envp) == -1)
		{
			perror("Error");
			free_tokens(av);
			free(full_command);
			exit(EXIT_FAILURE);
		}

		free(full_command);  // Free allocated memory for full_command
	}
	else
	{
		do {
			if (waitpid(forkRV, &status, WUNTRACED) == -1)
			{
				perror("Waitpid failed");
				return (-1);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));

		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
	}

	return (0);
}
