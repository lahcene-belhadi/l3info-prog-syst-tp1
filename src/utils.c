
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../header/utils.h"
#include "../header/tp1.h"


/**
 * Resizes an argv array to its correct size
 */
char** resize_argv(char** argv) {

    unsigned int size = 0;

    char* current = (char*) malloc(MAX_ARG * sizeof(char));

    current = argv[0];

    while (current) {
        
        size++;

        current = argv[size];

    }

    size++;

    // Resized argv
    char** new_argv = (char**) malloc(size * sizeof(char*));

    transfer_argv_data(argv, new_argv, size);

    free(argv);

    return new_argv;

}

/**
 * Transfers the data from an origin argv to another
 */ 
char** transfer_argv_data(char** argv, char** target, int size) {

    // Check if argv is empty
    if (argv[0] == NULL) {
        
        printf("Warning: argv is NULL\n");
        target[0] = NULL;

    }

    else {

        for (int i=0; i < size-1; i++) 
            target[i] = strdup(argv[i]);
        
        target[size] = NULL;

    }

    return target;

}
