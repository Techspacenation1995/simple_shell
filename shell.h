#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 100

void display_prompt();
char *read_command();
void execute_command(char *command);

#endif
