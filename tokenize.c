#include "shell.h"

/**
 * _strtok - strtok function implementation.
 *@str: str to tokenize.
 *@delimeter: delimeter.
 * Return: an array of strings.
 */

char **_strtok(char *str, char *delimeter)
{
	char **strings = NULL;
	char *cont, *copy = NULL;
	int i, j, token_count = 0;

	if (!str)
		return (NULL);
	copy = strdup(str);
	if (!copy)
		exit(EXIT_FAILURE);

	cont = strtok(copy, delimeter);
	while (cont != NULL) /* Count the no of tokens to allocate mem for string */
	{
		token_count++;
		cont = strtok(NULL, delimeter);
	}
	free(copy);
	strings = malloc(sizeof(char *) * (token_count + 1));
	/* Allocate memory for strings array */
	if (!strings)
		exit(EXIT_FAILURE);

	cont = strtok(str, delimeter); /* Tokenize the input string */
	while (cont != NULL)
	{
		strings[i] = strdup(cont);
		if (!strings[i])
		{
			for (j = 0; j < i; j++)
				free(strings[j]);
/* If memory allocation fails, free all previously allocated memory and exit */
			free(strings);
			exit(EXIT_FAILURE);
		}
		i++;
		cont = strtok(NULL, delimeter);
	}
	strings[i] = NULL;
	/* print_token(strings); */
	return (strings);
}

/**
 * free_tokens - Function to free the memory allocated by _strtok.
 * @tokens: tokens to free.
 */

void free_tokens(char **tokens)
{
	unsigned int i;

	if (!tokens)
		return;

	for (i = 0; tokens[i]; i++)
		free(tokens[i]);

	free(tokens);
}

/**
 * print_token - A function to print an array of strings
 * @token: strings to print
 */

void print_token(char **token)
{
	int i = 0;

	while (token[i])
	{
		printf("token[%d] = %s\n", i, token[i]);
		i++;
	}
}
