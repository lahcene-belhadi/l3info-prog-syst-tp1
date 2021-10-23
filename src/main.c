
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#include "../header/tp1.h"


int main(int argc, char* argv[]) {

    int nbcmd = 0;
    char** argv_ = file_to_argv("argv.txt", &nbcmd);

    display_argv(argv_);

    return 0;

}
