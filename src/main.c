
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#include "../header/tp1.h"


int main(int argc, char* argv[]) {

    int nbcmd = 0;
    char*** argv_ = file_to_argv("argv.txt", &nbcmd);

    char** first_argv = argv_[0];

    unsigned int i = 0;

    while (first_argv) {

        display_argv(first_argv);

        i++;

        first_argv = argv_[i];

    }

    return 0;

}
