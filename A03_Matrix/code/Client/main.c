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

#include "header.h"

//  Test User Input and ensure it is compatable
void testInput(int c, char* v[]) {
    if(c > 2) {
        printf("Excessive Arguments: ./client [Server IP]\n");
        exit(EXIT_FAILURE);
    }
}

//  Main body of the code
int main(int argc, char* argv[]) {
    //  Test User input
    testInput(argc, argv);

    //  Init Connection variables
    int connection = startClient();
    
    //	Recieve 2 Matrix from Server
    int sizeOfMatrix;
    read(connection, &sizeOfMatrix, sizeof(sizeOfMatrix));

    int MA[sizeOfMatrix][sizeOfMatrix];
    int MB[sizeOfMatrix][sizeOfMatrix];
    int MC[sizeOfMatrix][sizeOfMatrix];

	//	Recieve Matrix A
    read(connection, MA, sizeof(MA));

    int** Matrix_A = malloc(sizeof(int*) * sizeOfMatrix);
    
    for(int i=0; i<sizeOfMatrix; i++) {
        Matrix_A[i] = malloc(sizeof(int*) * sizeOfMatrix);
        for(int j=0; j<sizeOfMatrix; j++) {
            Matrix_A[i][j] = MA[i][j]; 
        }
    }

    printMatrix("Matrix_A", Matrix_A, sizeOfMatrix);
	
	//	Recieve Matrix B
    read(connection, MB, sizeof(MB));

    int** Matrix_B = malloc(sizeof(int*) * sizeOfMatrix);
    
    for(int i=0; i<sizeOfMatrix; i++) {
        Matrix_B[i] = malloc(sizeof(int*) * sizeOfMatrix);
        for(int j=0; j<sizeOfMatrix; j++) {
            Matrix_B[i][j] = MB[i][j]; 
        }
    }

    printMatrix("Matrix_B", Matrix_B, sizeOfMatrix);
	
    //	Calculate Matrix_C
    int** Matrix_C = multiplyMatrix(Matrix_A, Matrix_B, sizeOfMatrix);    

    for(int i=0; i<sizeOfMatrix; i++) {
	for(int j=0; j<sizeOfMatrix; j++) {
	    MC[i][j] = Matrix_C[i][j];
	}
    }

    printMatrix("Matrix_C", Matrix_C, sizeOfMatrix);

    //	Send Matrix_C back to the Server
    send(connection, &MC, sizeof(MC), 0);

    return 0;
}
