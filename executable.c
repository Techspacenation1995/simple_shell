#include "shell.h"

/**
 * execute - A function that executes a command.
 * @av: argument it takes
 *
 * Return: (-1)
 */
int execute(char *av[])
{
if (av == NULL || av[0] == NULL || av[0][0] == '\0')
{
_puts("Invalid command.\n");
return (-1);
}
if (access(av[0], F_OK) == 0)
{
return (executeCommand(av[0], av));
}
else if (av[0][0] != '/' && av[0][0] != '.')
{
return (executeFromPath(av[0], av));
}
else
{
_puts("Command not found");
return (-1);
}
}
/**
 * executecommand - executes a command with child process
 *@command: the command to execute
 *@args: the arguments
 *Return: -1 if failed or status value
 */
int executecommand(char *command, char *args[])
{
pid_t pid = fork();
int status;
if (pid < 0)
{
perror("Fork failed");
return (-1);
}
if (pid == 0)
{
if (execve(command, args, environ) == -1)
{
perror("Error");
free_tokens(args);
exit(EXIT_FAILURE);
}
}
else
{
waitForChildProcess(pid, &status);
return (WIFEXITED(status) ? WEXITSTATUS(status) : 0);
}
}

/**
 * waitForChildProcess - waits for the child process to run
 * @pid: process id of the child
 * @status: status value of the process
 */
void waitForChildProcess(pid_t pid, int *status)
{
do {
if (waitpid(pid, status, WUNTRACED) == -1)
{
perror("Waitpid failed");
exit(EXIT_FAILURE);
}
}
while
{
(!WIFEXITED(*status) && !WIFSIGNALED(*status));
}
}
/**
 * executeFromPath - executes command found in path
 * @command: the executable command
 * @args: arguements to command
 *Return: result or -1 if failed
 */
int executeFromPath(char *command, char *args[])
{
char *path = getenv("PATH");
if (path == NULL)
{
_puts("PATH environment variable not set.\n");
return (-1);
}
char *path_copy = strdup(path);
char *token = strtok(path_copy, ":");
while (token != NULL)
{
char *full_path = buildFullPath(token, command);
if (access(full_path, F_OK) == 0)
{
int result = executeCommand(full_path, args);
free(full_path);
free(path_copy);
return (result);
}
free(full_path);
token = strtok(NULL, ":");
}
free(path_copy);
_puts("Command not found");
return (-1);
}
/**
 * buildFullPath - builds the full pathe of the executable command
 * @directory: the location to store the command
 * @command: the command
 * Return: returns the full path
 */
char *buildFullPath(const char *directory, const char *command)
{
char *full_path;
full_path = malloc(strlen(directory) + strlen(command) + 2);
if (full_path == NULL)
{
perror("Memory allocation error");
exit(EXIT_FAILURE);
}
sprintf(full_path, "%s/%s", directory, command);
return (full_path);
}
