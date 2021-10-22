
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#include "../header/tp1.h"


int main(int argc, char* argv[]) {

    char** argv_ = line_to_argv("ls -l u/");

    int val = execute(argv_);

    return 0;

}
