#include "shell.h"
/**
 * Handle_arrays - converts a string into an array of strings
 * @command: the string to convert
 * @status: an integer representing the status of the command
 * Return: a pointer to a char array.
 */
char **Handle_arrays(char *command, int status)
{
	char *copied_line, *token, **argument_vector, *variable, *cmde;
	int i = 0, character_count;

	if (command[0] == '\0')
		return (NULL);
	copied_line = _strdup(command);
	if (copied_line == NULL)
		return (NULL);
	character_count = countCharacters(copied_line, ' ');
	argument_vector = malloc((character_count + 1) * sizeof(char *));
	token = _strtok(copied_line, TOK_D);

	cmde = handle_flags(token, command, argument_vector, status);
	argument_vector[i++] = cmde;
	while (token != NULL)
	{
		token = _strtok(NULL, TOK_D);
		if (token != NULL)
		{
			if (_strcmp("$$", token) == 0)
				cmde = get_pid();
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
			argument_vector[i++] = cmde;
		}
	}
	argument_vector[i] = NULL;
	free(copied_line);
	return (argument_vector);
}
