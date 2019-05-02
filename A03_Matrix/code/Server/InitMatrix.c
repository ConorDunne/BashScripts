/*
*       Student Name:       Conor Dunne 
*       Student Number:     17379526
*       Student Email:      conor.dunne2@ucdconnect.ie
* 
*       Initializes the 2 Matrix Int Arrays, matrix A and B
*/

#include <stdlib.h>

#include "header.h"

int** Matrix_A() {
    int** M = malloc(sizeof(int*) * N);
    
    for(int i=1; i<N+1; i++) {
        M[i-1] = malloc(sizeof(int*) * N);
        for(int j=1; j<N+1; j++) {
            M[i-1][j-1] = (i*j); 
        }
    }
    
    return M;
}

int** Matrix_B() {
    int** M = malloc(sizeof(int*) * N);
    
    int count = 1;
    for(int i=1; i<N+1; i++) {
        M[i-1] = malloc(sizeof(int*) * N);
        for(int j=1; j<N+1; j++) {
            M[i-1][j-1] = count++; 
        }
    }
    
    return M;
}

int** EmptyMatrix() {
    int** M = malloc(sizeof(int*) * N);
    
    for(int i=1; i<N+1; i++) {
        M[i-1] = malloc(sizeof(int*) * N);
        for(int j=1; j<N+1; j++) {
            M[i-1][j-1] = 0; 
        }
    }
    
    return M;
}

int** initMatrix(int matrixID) {
    int** Matrix;
    
    switch(matrixID) {
        case 0:
            Matrix = Matrix_A();
            printMatrix("Matrix A", Matrix);
            break;
        case 1:
            Matrix = Matrix_B();
            printMatrix("Matrix B", Matrix);
            break;
        case -1:
            Matrix = EmptyMatrix();
            break;
    }
    
    return Matrix;
}

int** transposeMatrix(int** M) {
    int** M2 = initMatrix(-1);
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            M2[i][j] = M[j][i];
        }
    }
    
    printMatrix("Matrix T", M2);
    return M2;
}
