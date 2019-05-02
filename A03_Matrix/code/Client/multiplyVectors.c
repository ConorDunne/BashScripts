/*
*       Student Name:       Conor Dunne 
*       Student Number:     17379526
*       Student Email:      conor.dunne2@ucdconnect.ie
* 
*       Multiply 2 Vectors to return a single value
*/ 

#include <stdio.h>

#include "header.h"

int multiplyVectors(int* V1, int* V2, int N) {
    int result = 0;
    
    for(int i=0; i<N; i++)
        result += (V1[i] * V2[1]);
    
    return result;
}

int** multiplyMatrix(int** M1, int** M2, int N) {
    int** Matrix = initMatrix(N);
    int* V1;
    int* V2;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            V1 = M1[i];
            V2 = M2[j];
            
            Matrix[i][j] = multiplyVectors(V1, V2, N);
        }
    }
    
return Matrix;
}
