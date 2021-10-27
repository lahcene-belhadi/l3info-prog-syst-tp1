
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "../header/tp1.h"
#include "../header/utils.h"


/**
 * Receives commands from the terminal and execute them
 */
void minibash(void) {

    // Run until it receives an interrupt signal
    while (1) {

        printf("Enter a command > ");

        // Receive the input
        char* input = (char*) malloc(MAX_ARG * sizeof(char));
        
        // Reads from the standard input
        char* check_eof = fgets(input, MAX_ARG, stdin);

        // If the user presses ctrl+d 
        if (check_eof == NULL)
            exit(0);

        // Build argv
        char** argv_ = line_to_argv(input);

        // Execute the command
        int value = execute(argv_);

        if (value != 0) {

            printf("An error occured : %d\n", value);

        }

    }

}

/** 
 * Receives a command, execute it but don't wait the end of the process
 */
int exec_batch(char ** command) {

    // Init
    int ret_val, ret_child, wchild = 0;

    // Create a child and return the pid
    int pid = fork();

    // If we're currently in the child (pid == 0)
    if (pid == 0) {

        // Execute the command
        ret_val = execvp(command[0], command);

        // If the command didn't encounter any problem
        if (ret_val != -1) 
            exit(EXIT_SUCCESS);
        
        else
            exit(ret_val);

    }
    // If it's the father
    else if (pid > 0) 
        // Get the child return value
        ret_child = 0;

    return 0;

}

/**
 * Executes all the commands contained in a file
 */
void exec_file_batch(char * filename) {

    int nbcmd = 0;
    char*** commands = file_to_argv(filename, &nbcmd);

    int retval = 0;

    for (int i=0; i < nbcmd; i++) {
    
        char** cmd = commands[i];
        retval = exec_batch(cmd);

    }

    // Wait all the process to end
    int ret = 0;
    int res;

    for (int i=0; i < nbcmd; i++)
        res = wait(&ret);

}

/**
 * Reads commands from a file and execute them
 */
void exec_file(char* filename) {

    int nbcmd = 0;
    char*** commands = file_to_argv(filename, &nbcmd);

    for (int i=0; i < nbcmd; i++) {

        char** command = commands[i];

        exec_batch(command);

    }

    printf("exec_file: FIN\n");

}

/**
 * Reads a file and extracts its content to an argv array
 */
char*** file_to_argv(char* filename, int* nbcmd) {

    // Array of argv
    char*** arr_argv = (char***) malloc(MAX_CMD * sizeof(char**));

    // Open the file
    FILE* data = fopen(filename, "r");

    if (data == NULL) {
     
        printf("Error : Unable to open the file \"%s\".\n", filename);
        exit(EXIT_FAILURE);
    
    }

    // Stores the line read from the file
    char* line = (char*) malloc(MAX_ARG);

    line = fgets(line, MAX_ARG, data);

    // Count the number of commands
    unsigned int nb = 0;

    while (line) {
        
        // Add line to argv
        char** argv_ = line_to_argv(line);

        // Add argv to the array of argv
        arr_argv[nb] = argv_;

        nb++;

        // Move to the next line
        line = fgets(line, MAX_ARG, data);

    }

    *nbcmd = nb;

    fclose(data);

    return arr_argv;

}

/**
 * Converts the command line to the argv array
 */
char** line_to_argv(char* line) {

    // Prepare the argv array
    char** arg = (char**) malloc(MAX_ARG * sizeof(char*));

    // Copy the line
    char* cp_line = strdup(line);

    // Get the current word
    char* word = strtok(cp_line, " \t\n");

    // Split the line
    unsigned int i = 0;

    while (word) {

        // Copy the current word into the argv 
        arg[i] = strdup(word);

        // Move to next word
        word = strtok(NULL, " \t\n");

        i++;

    }

    // Add NULL at the end of the argv
    arg[i] = NULL;

    arg = resize_argv(arg);

    return arg;

}

/**
 * Converts the argv array into a command line
 */
char* argv_to_line(char** argv_) {

    // Command line
    char* line = (char*) malloc(MAX_ARG);

    // Get the first word
    char* current = argv_[0]; 

    // Add each word to the lien
    unsigned int i = 0;

    while (current) {

        // Add the word
        line = strcat(line, current);
        line = strcat(line, " ");

        // Move to the next word
        i++;
        current = argv_[i];

    }

    return line;

}

/**
 * Displays the content of the argv array
 */
void display_argv(char** argv_) {

    // Contains the first word
    char* current = argv_[0];

    // Display the content of argv
    unsigned int index = 0;

    while (current) {

        // Display the current arg
        printf("Arg %d : %s \n", index, current);

        // Move to the next arg
        index++;
        current = argv_[index];

    }

}

/**
 * Execute the command stored in argv
 */
int execute(char** argv_) {

    // Init
    int ret_val, ret_child, wchild = 0;

    // Create a child and return the pid
    int pid = fork();

    // If we're currently in the child (pid == 0)
    if (pid == 0) {

        // Execute the command
        ret_val = execvp(argv_[0], argv_);

        // If the command didn't encounter any problem
        if (ret_val != -1) 
            exit(EXIT_SUCCESS);
        
        else
            exit(ret_val);

    }
    // If it's the father
    else if (pid > 0) {

        // Get the child return value
        ret_child = 0;

        // Wait for the child to finish
        wchild = wait(&ret_child);

    }

    return WEXITSTATUS(ret_child);

}
