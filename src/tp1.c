
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "../header/tp1.h"


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

    // Prepare re allocation
    char** true_argv = (char**) malloc(i * sizeof(char*));

    // Add all the content of argv_ to true_argv
    unsigned int j = 0;

    while (j < i) {

        // Transfer data from arg to true_argv
        true_argv[j] = strdup(arg[j]);
        j++;

    }

    // Release previous array from the heap
    free(arg);

    return true_argv;

}

/**
 * Converts the argv array into a command line
 */
char* argv_to_line(char** argv_) {

    // Command line
    char* line = (char*) malloc(100);

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