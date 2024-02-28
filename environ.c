#include"shell.h"

/**
 * _getenv - a fUnction to get enviroment variabe
 * @name: name of enviroment variable to get the value of
 * Return: the value of the enviroment varable
*/

char *_getenv(const char *name)
{
	int i;
	char *variable_name;
	char *variable_value;
	char *value = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		variable_name = strtok(environ[i], "=");
		variable_value = strtok(NULL, "=");

		if (strcmp(variable_name, name) == 0)
		{
			value = variable_value;
			break;
		}
	}
	return (value);
}
