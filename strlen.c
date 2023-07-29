#include "shell.h"

/**
 * my_strlen - A function that calculate the length of string
 * @str: pointer to a string.
 *
 * Return: The length of string on success.
 */


size_t _strlen(const char *str)
{
	size_t length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}
