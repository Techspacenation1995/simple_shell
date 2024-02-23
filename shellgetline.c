#include "shell.h"

/**
 * shellgetline - shell inbuilt getline fuction
 *
 * Return: Returns the input received.
 */

char *shellgetline(void)
{
	char *buffers = NULL;
	size_t n = 0;

	if (getline(&buffers, &n, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(buffers);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(buffers);
			perror("No data input");
			exit(EXIT_FAILURE);
		}
	}

	return (buffers);
}
