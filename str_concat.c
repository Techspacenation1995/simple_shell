#include "shell.h"

/**
 * _strcat - A function that concatenate two strings
 * @src: Source string
 * @dest: destination string
 *
 * Return: void
 */

void _strcat(char *dest, char *src)
{
	int dest_len = 0;

	/*Find the end of the destination string*/
	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}

	/* Append characters from the source strng to the destination string */

	int i = 0;

	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}

	/* Add the null_terminator at the end of the concatenated string */
	dest[dest_len + i] = '\0';
}
