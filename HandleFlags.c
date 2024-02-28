#include "shell.h"

/**
 * handle_flags - function to handle flags
 * @token: tokenised string
 * @command: array of commands
 * @argument_vector: the arguement vectos
 * @status: status count
 * Return: flags
*/
char *handle_flags(char *token, char *command,
char **argument_vector, int status)
{
		char *variable, *cmde, *copied_line;

	copied_line = command;
		if (token == NULL)
	{
		free(argument_vector);
		free(copied_line);
		return (NULL);
	}
	if (_strcmp("$$", token) == 0)
		cmde = get_process_id();
	else if (_strcmp("$?", token) == 0)
		cmde = get_status(status);
	else if ((token[0] == '$') && (token[1]))
	{
		variable = _getenv(&token[1]);
		if (variable)
			cmde = _strdup(variable);
		else
			cmde = _strdup("");
	}
	else
		cmde = _strdup(token);

	return (cmde);
}
