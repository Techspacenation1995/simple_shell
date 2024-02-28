#include "shell.h"
/**
 * pipedCount - counts the occurrences of a character in  string
 *
 * @string: the string to search for the character
 * @a: the character to search for
 * Return: the number of occurrences
 */
unsigned int pipedCount(char *string, char a)
{
	unsigned int c = 0;

	while (*string != '\0')
	{
		if (*string == a)
			c++;
		string++;
	}
	return (c + 1);
}
