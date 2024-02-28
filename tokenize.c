#include"shell.h"
/**
 * _strtok - a function that tokenize a string.
 * @string: string that was parsed.
 * @delim: delimeter.
 * Return: tokenized string.
 *
*/
char *_strtok(char *string, const char *delim)
{
	return (strtok(string, delim));
}
