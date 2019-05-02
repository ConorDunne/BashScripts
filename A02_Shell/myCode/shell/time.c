/*
*       Student Name:       Conor Dunne 
*       Student Number:     17379526
*       Student Email:      conor.dunne2@ucdconnect.ie
* 
*       Prints current date and time in the following format
*       Format [dd/MM hh:mm]#
*       dd = Day    MM = Month  hh = Hour   mm = Minute
*/

#include <stdio.h>
#include <time.h>

#include "header.h"

void getTime(void) {
    time_t rawtime;
    struct tm *info;

    time( &rawtime );
    info = localtime(&rawtime);
    
    printf("[%02d/%02d %02d:%02d]", info->tm_mday, info->tm_mon, info->tm_hour, info->tm_min);
}
