/*
*       Student Name:       Conor Dunne 
*       Student Number:     17379526
*       Student Email:      conor.dunne2@ucdconnect.ie
* 
*       Header Function for Command Shell
*/

#include <limits.h>
#include <stdio.h>

int main(void);
/*  ----------------------------------------------------------------------------------------------------------  */
//  Global Path Variable and path commands
char WorkingDirectory[PATH_MAX];

int setPath(v oid);                      //  Changes Global Variable WorkingDirectory to Current Directory
int cd(char *p);                        //  Changes path and updates Working Directory

/*  ----------------------------------------------------------------------------------------------------------  */
//  Command Input Functions
int command(void);                      //  Reads and Runs inputted commands

void processCommand(char* command);     //  Processes Command and passes it to funFork
void getTime(void);                      //  Prints current date and time
/*  ----------------------------------------------------------------------------------------------------------  */
//  Command Run Functions
void runFork(char** arg);          //  Runs inputted commands in child fork

/*  ----------------------------------------------------------------------------------------------------------  */

//  Catch Signal
int catch_signal(void);                 //  Catches Ctrl+C SIGINT signal
