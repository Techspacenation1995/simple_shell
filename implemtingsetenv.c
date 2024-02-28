#include <stdio.h>
#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
* implement_setenv - implementation of sentev fuction
* @name: The name of the environment variable
* @value: The value to be assigned to the environment variable
* @pointer: Pointer to the list_paths structure
* This function sets the value of an environment variable.
*/

void implement_setenv(char *name, char *value, list_paths *pointer)
{
	int i = 0;
	char *full_env = NULL;

	if (name == NULL || value == NULL)
	{
		return;
	}
	if (pointer == NULL)
	{
		return;
	}
	i = _strlen(name) + _strlen(value) + 2;
	full_env = malloc(i);
	if (full_env == NULL)
	{
		return;
	}
	_strcpy(full_env, name);
	_strcat(full_env, "=");
	_strcat(full_env, value);
	full_env[i - 1] = '\0';
	free(full_env);

}
