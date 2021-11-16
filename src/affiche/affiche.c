// Packages
#include "affiche.h"


/**
 * Displays the message each second until it reaches the duration limit
 *
 * * `message` - The string literal representing the message to display
 * * `duration` - The unsigned integer corresponding to the duration
 */
void display_until(char* message, unsigned int duration) {

    time_t begin = time(&begin);

    while (!has_reach_time_limit(&begin, &duration)) {
        
        printf("%s\n", message);
        sleep(1);

    }

}

/**
 * Tells if the time limit has been reached
 *
 * * `begin` - The time when we start counting
 * * `limit` - The unsigned integer that represents the time limit
 */
bool has_reach_time_limit(const time_t* begin, const unsigned int* limit) {

    // Get the current time
    time_t current = time(&current);

    // Calculate the elapsed time
    time_t elapsed = current - *begin;

    if (elapsed < *limit)
        return false;
    
    return true;

}
