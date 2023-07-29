#include "shell.h"

/**
 * main - Entry point
 * @ac: Argument counts
 * @av: Argument vector
 * @env: Environment variable
 *
 * Return: Zero on success.
 */

int main(int ac, char **av, char **env)
{
	/* Ignore unused arguments */

	(void)ac;
	(void)av;

	run_shell(env);
	return (0);

}
