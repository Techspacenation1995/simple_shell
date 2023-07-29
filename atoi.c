#include "shell.h"

/**
 * int_to_str - A function that converts an integer to a string
 * @num: Number of arguments passed
 * @str: Pointer to a string
 *
 * Return: Void
 */

void int_to_str(int num, char *str)
{
	int i = 0;

	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return;
	}

	while (num != 0)
	{
		str[i++] = (num % 10) + '0';
		num = num / 10;
	}
	str[i] = '\0';

	/* Reverse the string */

	int len = _strlen(str);

	for (int j = 0; j < (len / 2); j++)
	{
		char temp = str[j];

		str[j] = str[len - j - 1];
		str[len - j - 1] = temp;
	}
}
