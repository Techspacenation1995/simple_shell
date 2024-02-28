#include"shell.h"
/**
 * convertNum2char - Converts an integer to a string.
 * @number: The integer to be converted.
 *
 * Return: The string representation of the integer,
 * or NULL if failed
 */

char *convertNum2char(int number)
{
	int count = 0, temprory = number;
	char *copied_number;

	if (number == 0)
		count = 1;
	else
	{
		while (temprory != 0)
		{
			temprory = temprory / 10;
			count++;
		}
	}

	copied_number = malloc(sizeof(char) * (count + 1));
	if (!copied_number)
	{
		perror("malloc error");
		return (NULL);
	}

	copied_number[count] = '\0';
	while (count != 0)
	{
		count--;
		copied_number[count] = '0' + number % 10;
		number = (number / 10);
	}

	return (copied_number);
}
