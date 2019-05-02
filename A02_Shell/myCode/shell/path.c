/*
*       Student Name:       Conor Dunne 
*       Student Number:     17379526
*       Student Email:      conor.dunne2@ucdconnect.ie
* 
*       Shell Command
*       Prints current directory without new line so '#' can be added
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

#include "header.h"

char cwd[PATH_MAX];

//  Changes Global Variable WorkingDirectory to Current Directory
int setPath(void) {
    if(getcwd(cwd, sizeof(cwd)) == NULL) {
        printf("ERROR: unable to get working directory");
        exit(EXIT_FAILURE);
    } else {
        strcpy(WorkingDirectory, cwd);
    }
    
    return 0;
}

//  Changes path and updates Working Directory
int cd(char* p) {
    if(strcmp(p, "") == 0) {
        if(chdir(getenv("HOME")) != 0)
            perror("Error");
        else
            setPath();
    } else {
        if(chdir(p) != 0)
            perror("Error");
        else
            setPath();
    }
    
    return 0;
}
