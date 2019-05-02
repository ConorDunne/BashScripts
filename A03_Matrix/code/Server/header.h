/*
*       Student Name:       Conor Dunne 
*       Student Number:     17379526
*       Student Email:      conor.dunne2@ucdconnect.ie
* 
*       Header Function for Command Shell
*/

#define N 3
#define PORTNUM 2343

int main(int argv, char* argc[]);

/*  ----------------------------------------------------------------------------------------------------------  */
//  Read Matrix from files
int** initMatrix(int matrixID);

void printMatrix(char* title, int** Matrix);
//int** multiplyMatrix(int** M1, int** M2);
int** transposeMatrix(int** M);
int startServer(void);
