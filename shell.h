#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 2048

void display_prompt();
char *read_command();
void execute_command(char *cmd, char **env);
char *find_executable(char *cmd);
int _strcmp(const char* str1, const char* str2);
size_t _strlen(const char *str);
void _strcat(char *dest, char *src);
void _strcpy(char *dest, char *src);
void run_shell(char **env);
void int_to_str(int num, char *str);

#endif
