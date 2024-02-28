#include "shell.h"
/**
* no_file_handler - handles errors that occures during operation
* @program: the name of the program attempting to open non exisitint
* @number: a counter variable to keep track.
* @file_name: the name of the file that cannot be opened
*
* Return : void.
*/
void no_file_handler(char *program, int number, char *file_name)
{

	char *counter_s;

	counter_s = convertNum2char(number);
	write(STDERR_FILENO, program, _strlen(program));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, counter_s, _strlen(counter_s));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "Can't open ", 11);
	write(STDERR_FILENO, file_name, _strlen(file_name));
	write(STDERR_FILENO, "\n", 1);
}
