
// Packages
#include "affiche.h"


int main(int argc, char** argv) {

    if (argc > 2) {

        // Convert argv[1] to a long integer
        unsigned long limit = strtol(argv[2], NULL, 10);
        display_until(argv[1], limit);
    
    } else 
        printf("You passed %d arguments: expected 3.\n", argc);

    return 0;

}
