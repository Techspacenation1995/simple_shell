#include "shell.h"

/**
 * display_prompt - A function that prints the number of string to the screen
 *
 * Return: Void.
 */

void display_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
