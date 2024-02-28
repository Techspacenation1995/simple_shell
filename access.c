#include "shell.h"
/**
  * confirmaccess - a function that checks the access
  * for a given command in the command line.
  *
  * @current: current path turned into linked lists
  * @command:  line from user entered by getline and path list
  *
  * Return: full path of the command
  */

char *confirmaccess(char *command, list_paths *current)
{
	char *full_path;
	int found_path, length, command_length, current_path_legnth;

	if (current == NULL)
		return (NULL);
	while (current)
	{
		current_path_legnth = _strlen(current->path);
		command_length = _strlen(command);
		length = (current_path_legnth + command_length + 2);
		full_path = (char *)malloc(length * sizeof(char));
		_strcpy(full_path, current->path);
		_strcat(full_path, "/");
		_strcat(full_path, command);
		found_path = 0;
		if (access(full_path, X_OK) == 0)
		{
			found_path = 1;
			break;
		}
		else
			free(full_path);
		current = current->next;
	}
	if (found_path)
		return (full_path);

	else
		return (NULL);
}
