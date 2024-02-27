#include "shell.h"

/**
 * print_token - A function to print an array of strings
 * @tokens: strings to print
 */

void print_token(char **tokens)
{
	int i = 0;
	char *store;

	while (token[i])
	{
		store = tokens[i];
		_puts(store);
		i++;
	}
}

/**
 * free_token - Function to free the memory allocated by _strtok function
 * @tokens: tokens to free
 */

void free_token(char **tokens)
{
	unsigned int j;

	if (!tokens)
		return;

	for (j = 0; tokens[j]; j++)
		free(tokens[j]);

	free(tokens);
}
