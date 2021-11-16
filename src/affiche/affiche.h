#ifndef SRC_AFFICHE_AFFICHE_H
#define SRC_AFFICHE_AFFICHE_H

// Lib
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>


// Functions
void display_until(char*, unsigned int);

// Utils
bool has_reach_time_limit(const time_t*, const unsigned int*);


#endif
