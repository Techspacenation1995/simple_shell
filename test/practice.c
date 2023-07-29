#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

void display_prompt() {
    write(STDOUT_FILENO, "$ ", 2);
}

char *read_command() {
    char *command = NULL;
    size_t bufsize = 0;
    ssize_t linelen = getline(&command, &bufsize, stdin);

    if (linelen == -1) {
        write(STDOUT_FILENO, "\n", 1);
        free(command);
        return NULL;
    }

    // Remove the trailing newline character, if present
    if (linelen > 0 && command[linelen - 1] == '\n') {
        command[linelen - 1] = '\0';
    }

    return command;
}

void execute_command(char *command) {
    // Fork a child process to execute the command
    pid_t pid = fork();

    if (pid == -1) {
        // Error occurred while forking
        perror("fork");
    } else if (pid == 0) {
        // Child process

        // Split the command into executable and arguments
        char *args[MAX_COMMAND_LENGTH];
        char *token = strtok(command, " ");
        int i = 0;
        while (token != NULL && i < MAX_COMMAND_LENGTH - 1) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL; // NULL-terminate the arguments array

        // Execute the command using execve
        if (execve(args[0], args, NULL) == -1) {
            // Failed to execute the command
            perror("execve");
            exit(1);
        }

        // Child process should not reach here unless execve fails
        exit(0);
    } else {
        // Parent process

        // Wait for the child process to complete
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    while (1) {
        // Display prompt and wait for user input
        display_prompt();
        
        // Read the user input (command)
        char *command = read_command();
        if (command == NULL) {
            // End of file (Ctrl+D) or error
            break;
        }

        // Execute the command
        execute_command(command);

        // Free the dynamically allocated memory for command buffer
        free(command);
    }

    return 0;
}

