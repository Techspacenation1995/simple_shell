#include "shell.h"

/**
 * _strcpy - A function that copies a string from source to destination
 * @src: A pointer to a string that house the source literals
 * @dest: A pointer to a string that house the address of the destination
 *
 * Return: void
 */

void _strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
