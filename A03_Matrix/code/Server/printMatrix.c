/*
*       Student Name:       Conor Dunne 
*       Student Number:     17379526
*       Student Email:      conor.dunne2@ucdconnect.ie
* 
*       To print an int** matrix
*/ 

#include <stdio.h>

#include "header.h"

void printMatrix(char* title, int** Matrix) {
    printf("--------\n");
    
    printf("%s\n", title);
    
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            printf("%d ",Matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}
