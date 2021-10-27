
#include "header/tp1.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100


int main(int argc, char* argv[]) {

    char* filename = (char*) malloc(MAX_LEN * sizeof(char));

    if (argc > 1) {

        filename = argv[1];
        exec_file_batch(filename);
    
    } else 
        printf("Error: No filename provided.\n");
    
    return 0;
        
}