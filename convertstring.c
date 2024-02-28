#include"shell.h"
/**
 * convertint - Converts an integer to a string.
 * @n: The integer to convert.
 * @str: The buffer to store the resulting string.
 * Return : nothing
 */
void convertint(int n, char *str)
{
	int store;
	int i = 0;

	if (n == 0)
	{
		str[i++] = '0';
	}
	store = n;
	while (store > 0)
	{
		store /= 10;
		i++;
	}
	store = n;
	while (i > 0)
	{
		str[--i] = store % 10 + '0';
		store /= 10;

	}
	str[i] = '\0';

}
