/*
*       Student Name:       Conor Dunne 
*       Student Number:     17379526
*       Student Email:      conor.dunne2@ucdconnect.ie
* 
*       Catches Ctrl+C SIGINT signal
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "header.h"

//  Prints message if Ctrl+C is caught
void caught(int num) {
    printf("\n");
    getTime();
    printf("# ");
    fflush(stdout);
}

//  Tests if Ctrl+C is pressed
int catch_signal(void) {
    if(signal(SIGINT, caught) == SIG_ERR) {
        printf("ERROR: Cannot catch signal");
        exit(EXIT_FAILURE);
    }
    return 0;
}
