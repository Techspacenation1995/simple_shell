#include"shell.h"
/**
 * get_status - Retrieves the string representation of a status value.
 *
 * @n: The status value to convert to a string.
 *
 * Return: A pointer to a string representing the status value.
 */
char *get_status(int n)
{
	char *status;

	status = convertNum2char(n);

	return (status);
}
