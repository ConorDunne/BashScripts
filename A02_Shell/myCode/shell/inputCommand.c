/*
*       Student Name:       Conor Dunne 
*       Student Number:     17379526
*       Student Email:      conor.dunne2@ucdconnect.ie
* 
*       Reads and Processes inputted Commands
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "header.h"

//  Process the command into a string array (Removes new line character, adds NULL to the end, and adds ../commands/ to the start)
void processCommand(char* command) {
    //  Initialize Variables
    char** args;
    char* token = NULL;
    
    int count = 0;
    char* delim = "\t\n\r ";
    
    //  Prepare args and token for use
    args = malloc(sizeof(char*));
    token = strtok(command, delim);
    
    //  Split command into seperate strings in args
    while(token != NULL) {
        args[count] = token;
        count++;
        args = realloc(args, (count+1) * sizeof(char*));
        token = strtok(NULL, delim);
    }
    
    //  Add NULL to the end of args
    args[count] = NULL;
    count++;
    args = realloc(args, (count+1) * sizeof(char*));
    
    runFork(args);
}
