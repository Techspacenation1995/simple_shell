#include "shell.h"

/**
 * prompt - A function that prompts a user.
 *
 * Return: void
 */

void display_prompt(void)
{
	_putchar('$');
	_putchar(' ');
}

/**
 * _putchar - writes character c to stdout.
 * @charr: The character to write.
 *
 * Return: On success 1.
 * On error, -1 is returned, and error is set appropriately
 */

int _putchar(char charr)
{
	return (write(1, &charr, 1));
}
