
#include <stdlib.h>
#include <stdio.h>

#include "header/tp1.h"

#define MAX_LEN 100


int main(int argc, char* argv[]) {

    if (argc > 1) 
        exec_file_batch(argv[1]);
    
    else 
        printf("Error: No filename provided.\n");
    
    return 0;
        
}