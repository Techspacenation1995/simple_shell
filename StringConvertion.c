#include"shell.h"
/**
 * _conv_string - Converts a string to an integer.
 * @s: The string to be converted, input by user
 *
 * Return: The converted integer,
 * or -1 on conversion error.
 */
int _conv_string(char *s)
{
	unsigned int y, x;
	char positive;

	x = 0;
	y = 0;

	while (s[x] != '\0')
	{
		/* Check if the character is a non-digit */
		if (!((s[x] >= '0') && (s[x] <= '9')))
		{
			return (-1);
		}

		/* Check if the character is a digit */
		if (((s[x] >= '0') && (s[x] <= '9')))
		{
			y = (y * 10) + (s[x] - '0');
		}
		else if (s[x] == '+')
		{
			positive++;
		}

		x++;
	}

	/* Return the converted integer */
	return (y);
}
