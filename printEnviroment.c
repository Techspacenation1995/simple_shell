#include"shell.h"

/**
 * printEnviroment - Prints the environment variables.
 * @status: A pointer to an integer variable to set the status.
 * Return:nothing
 */
void printEnviroment(int *status)
{
	int n;

	for (n = 0; environ[n] != NULL; n++)
	{
		write(STDOUT_FILENO, environ[n], _strlen(environ[n]));
		write(STDOUT_FILENO, "\n", 1);
	}
	*status = 0;
}
