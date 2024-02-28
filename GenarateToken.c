#include"shell.h"
/**
 * GenerateToken - Processes a token and returns the corresponding string.
 * @string: The input string that needs processing.
 * @status: An integer representing the status of the command.
 * Return: A dynamically allocated string representing the processed token.
 */
char *GenerateToken(char *string, int status)
{
	char *cmde, *variable;

	cmde = NULL;
	variable = NULL;

	if (_strcmp("$$", string) == 0)
		cmde = get_pid();
	else if (_strcmp("$?", string) == 0)
		cmde = get_status(status);
	else if (string[0] == '$' && string[1] != '\0')
	{
		variable = _getenv(&string[1]);
		cmde = (variable != NULL) ? _strdup(variable) : _strdup("");
	}
	else
		cmde = _strdup(string);
	return (cmde);
}
