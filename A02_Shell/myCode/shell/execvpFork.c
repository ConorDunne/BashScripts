/*
*       Student Name:       Conor Dunne 
*       Student Number:     17379526
*       Student Email:      conor.dunne2@ucdconnect.ie
* 
*       Runs inputted commands in child fork
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#include "header.h"

void forkProcess(char** arg) {
    if(fork() == 0) {        
        //  Child Fork - Run Command
        execvp(arg[0], arg);
    } else {
        //  Parent Fork - wait for child to finish
        wait(NULL);
    }
}

void runFork(char** arg) {
    if(strcmp(arg[0], "cd") != 0)
        forkProcess(arg);
    else
        chdir(arg[1]);
    
}
