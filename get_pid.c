#include "shell.h"
/**
 * get_pid - Retrieves the string representation of the current
 * process ID.
 *
 * Return: A pointer to a string representing the process ID.
 */

char *get_pid()
{
	char *ppid_s;
	pid_t pid = getpid();

	/* Convert the process ID to a string */
	ppid_s = convertNum2char(pid);

	/* Return the string representation of the process ID */
	return (ppid_s);
}
