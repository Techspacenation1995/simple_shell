#include "shell.h"

/**
 * main - Entry point of a c program
 *
 *
 * Return: 0 on sucess.
 */

int main()
{
	char *command = NULL;
	size_t bufsize = 0;
	pid_t pid;

	while (1) 
	{
		/* Display prompt and wait for user input */
		write_string("$ ");

		/* Read the user input (command) using getline */

		ssize_t linelen = getline(&command, &bufsize, stdin);
		if (linelen == -1)
		{
			/* End of file (Ctrl+D) or error */
			write_string("\n");
			break;
		}

		/* Remove the trailing newline character, if present */
		if (linelen > 0 && command[linelen - 1] == '\n')
		{
			command[linelen - 1] = '\0';
		}

		/* Fork a child process to execute the command */
		pid = fork();

		if (pid == -1)
		{
			/* Error occurred while forking */
			write_string("Error: Fork failed.\n");
		}
		else if (pid == 0)
		{
			/* Child process */

			/* Split the command into executable and arguments */
			
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
				/* Failed to execute the command */
				write_string("Error: Command not found.\n");
				exit(1);
			}

			/* Child process should not reach here unless execve fails */
			exit(0);
		}
		else
		{
			/* Parent process */

			/* Wait for the child process to complete */
			int status;
			
			waitpid(pid, &status, 0);
		}
	}

	/* Free the dynamically allocated memory for command buffer */
	free(command);
	return 0;
}
