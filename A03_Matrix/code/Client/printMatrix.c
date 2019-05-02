/*
*       Student Name:       Conor Dunne 
*       Student Number:     17379526
*       Student Email:      conor.dunne2@ucdconnect.ie
* 
*       To print an int** matrix
*/ 

#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int** initMatrix(int N) {
    int** M = malloc(sizeof(int*) * N);
    
    for(int i=1; i<N+1; i++) {
        M[i-1] = malloc(sizeof(int*) * N);
        for(int j=1; j<N+1; j++) {
            M[i-1][j-1] = 0; 
        }
    }
    
    return M;
}

void printMatrix(char* title, int** Matrix, int N) {
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
