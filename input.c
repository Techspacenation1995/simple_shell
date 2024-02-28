#include"shell.h"
/**
* input - checks if a file exists and is readable.
* @file: name of file to check
* This function checks if the file specified by
* @file exists and is readable.
*Return: pointer to file if it exists
*/
char *input(char *file)
{
char *command;
command = _strdup(file);

	return (command);
}
