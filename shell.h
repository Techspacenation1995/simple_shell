#ifndef MAIN_H
#define MAIN_H
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

#define NOT_FOUND 127
#define PERMISSION_DENIED 126
#define EXIT_ERROR 2

#define INTERACTIVE_MODE 1
#define NON_INTERACTIVE_PIPE 2
#define NON_INTERACTIVE_MODE 0
#define ERROR -1
#define TOK_D " \t\r\n\a\""


/**
 * struct list_paths - a struct made for nodes out of enviroment variable path
 * @path: enviroment variable path
 * @len: length of the path
 * @next: points to the next node
*/

typedef struct list_paths
{
	char *path;
	unsigned int len;
	struct list_paths *next;
} list_paths;

extern char **environ;
list_paths *tokenised();
size_t print_list(const list_paths *h);
void freeList(list_paths *head);
list_paths *node(list_paths **head, char *path);
unsigned int countCharacters(char *string, char character);
/*-----------*/

int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _conv_string(char *s);
void convertint(int n, char *str);
/*----------*/
void printEnviroment(int *status);
int mode(int argc);
char *confirmaccess(char *command, list_paths *current);
char *_getline(list_paths *current);
void free_array(char **argv);
void free_allocated(char *command, char **command_array);
void execute(char *path, char **av, char **env, int *status);
void scan_cmd_file(char *file);
char *input(char *file);
void free_list(list_paths *head);
char **Handle_arrays(char *line, int status);
char *num_to_char(int num);
void printError(char *shell_name, int count,
char *command_array, int type_of_error);
char *get_status(int n);
char *get_pid();
char *_getenv(const char *name);
int builtInCommands(char *command, char **command_array, list_paths *current,
char *shell_name, int count, int *status,
list_paths *env_list, char **command_lines, char **argv);
void nonbuiltin_handler(char **command_array, char *env[], int *status,
int count, list_paths *current, char *argv[]);
int implement_cd(char **command, char **argument);
void implement_setenv(char *name, char *value, list_paths *pointer);
char **scanCommands(int op_mode, char *file_name, char *shell_name);
char **handle_non_interactivefile(char *file_name, char *shell_name);
int checkdir(char *command, char **argument_vector, int count,
char **command_array, int *status, char *command_line_before);
char *convertNum2char(int number);
int linecount(char *line);
char **convert2Array(char *text_read);
void no_file_handler(char *program, int number, char *file_name);
unsigned int pipedCount(char *string, char a);
char **pipes_handler();
char *get_non_interactive_command(char **command_lines, int count);
void permission_handler(char **command_array, int count,
char *executable, int *status, char *command);
void process_command(char *command, int *status, char ***command_array);
int line_count(char *line);
char **allocate_vector(int size);
void free_vector(char **vector);
char *GenerateToken(char *string, int status);
int tokenize_command(char *command, int status, char **argument_vector);
char *handle_flags(char *token, char *command,
char **argument_vector, int status);
char *_strtok(char *string, const char *delim);
void free_whole(char **command_lines, int count, list_paths *env,
list_paths *current, char *command, char **command_array);
void exit_handler(char *command, char **command_array, list_paths *current,
char *shell_name, int count, int *status, list_paths *env,
char **command_lines);
void removeComments(char *input);


#endif
