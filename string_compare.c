#include "shell.h"

/**
 * _strcmp - A function that compares two strings
 * @str1: First pointer to constant character
 * @str2: Second pinter to the conctant character.
 *
 * Return: returns 1 if str1 > str2
 */

int _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return ((str1[i] < str2[i]) ? -1 : 1);
		}
		i++;
	}

	/* So we need to check the last character of the string */

	if (str1[i] == '\0' && str2[i] == '\0')
	{
		return (0); /*string are equal*/
	}
	else if (str1[i] == '\0')
	{
		return (-1); /* str1 is a substring of str2 */
	}
	else
	{
		return (1); /* str2 is a substring of str1 */
	}
}
