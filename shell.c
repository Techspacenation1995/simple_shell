#include "shell.h"

/**
 * main - Entry point
 *
 * Return: Zero on success.
 */

int main(void)
{
	while (1)
	{
		/* Display prompt and wait for user input */
		display_prompt();
		/* Read the user input (command) */
		char *command = read_command();

		if (command == NULL)
		{
			/* End of file (Ctrl+D) or error */
			break;
		}
		/* Execute the command */
		execute_command(command);
		/* Free the dynamically allocated memory for command buffer */
		free(command);
	}
	return (0);
}
