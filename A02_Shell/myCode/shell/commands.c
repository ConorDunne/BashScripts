/*
*       Student Name:       Conor Dunne 
*       Student Number:     17379526
*       Student Email:      conor.dunne2@ucdconnect.ie
* 
*       Reads and Runs inputted commands
*/

#include <stdio.h>
#include <string.h>

#include "header.h"

int command(void) {
    //  Init Variables
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    
    //  Print input symbol and read line
    getTime();
    printf("# ");
    if((read = getline(&line, &len, stdin)) == -1)
        return 0;
    
    //  Processes and Runs Command
    processCommand(line);

    return 1;
}
