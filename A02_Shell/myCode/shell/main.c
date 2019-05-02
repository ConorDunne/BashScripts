/*
*       Student Name:       Conor Dunne 
*       Student Number:     17379526
*       Student Email:      conor.dunne2@ucdconnect.ie
* 
*       Main body of my shell
*       Loops the idle state
*/

#include <stdio.h>

#include "header.h"

int main(void) {
    setPath();
    int loop = 1;
    
    catch_signal();
    
    while(loop) {
        fflush(stdout);
        loop = command();
    }
    
    printf("\n> Goodbye\n");
}
