/*
*       Student Name:       Conor Dunne 
*       Student Number:     17379526
*       Student Email:      conor.dunne2@ucdconnect.ie
* 
*       Main body of my shell
*       Calls the other Commands
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "header.h"

//  Test User Input and ensure it is compatable
void testInput(int c, char* v[]) {
    if(c != 3) {
        printf("Insufficient Arguments: ./server [matrix size] [number of workers]\n");
        exit(EXIT_FAILURE);
    }    
    
    int n = atoi(v[1]);
    int p = atoi(v[2]);
        
    if(n%p != 0) {
        printf("Error: Number of Workers must divide Matrix Size\n");
        exit(EXIT_FAILURE);
    }
}

//  Main body of the code
int main(int argc, char* argv[]) {
    //  Test User input
    testInput(argc, argv);
    
    //  Init Matrix variables
    int** Matrix_A = initMatrix(0);
    int** Matrix_B = initMatrix(1);
    int** Matrix_C = initMatrix(-1);
    
    Matrix_B = transposeMatrix(Matrix_B);
    
    //  Init Connection variables
    int connection = startServer();   
 	
    int MatrixSize = N;

    int MA[N][N];
    int MB[N][N];
    int MC[N][N];

    for(int i=0; i<N; i++) {
	for(int j=0; j<N; j++) {
	    MA[i][j] = Matrix_A[i][j];
	    MB[i][j] = Matrix_B[i][j];	    
	}
    }

    send(connection, &MatrixSize, sizeof(MatrixSize), 0);
    send(connection, &MA, sizeof(MA), 0);
    send(connection, &MB, sizeof(MB), 0);

    read(connection, MC, sizeof(MC));
    
    for(int i=0; i<N; i++) {
	for(int j=0; j<N; j++) {
	    Matrix_C[i][j] = MC[i][j];
	}
    }

    printMatrix("Matrix C", Matrix_C);
  
   return 0;
}
