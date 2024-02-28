#include"shell.h"
/**
 * convert2Array - converts text **strings
 *
 * @text_read: the text to convert
 *
 * Return: a pointer to a char array containing the converted text
 */
char **convert2Array(char *text_read)
{
	char *token, *command;
	char **command_lines;
	int i;
	unsigned int characters_count;

	characters_count = 0;
	command_lines = NULL;
	i = 0;
	characters_count = pipedCount(text_read, '\n');
	command_lines = (char **)malloc((characters_count + 1) * sizeof(char *));
	token = strtok(text_read, "\n");
	command = _strdup(token);
	command_lines[i++] = command;
	while (token != NULL)
	{
		token = _strtok(NULL, "\n");
		if (token != NULL)
		{
			command = _strdup(token);
			command_lines[i++] = command;
		}
	}
	free(text_read);
	command_lines[i] = NULL;
	return (command_lines);
}
