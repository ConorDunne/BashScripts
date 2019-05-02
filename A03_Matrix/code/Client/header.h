/*
*       Student Name:       Conor Dunne 
*       Student Number:     17379526
*       Student Email:      conor.dunne2@ucdconnect.ie
* 
*       Header Function for Command Shell
*/

#define PORTNUM 2343

int main(int argv, char* argc[]);

/*  ----------------------------------------------------------------------------------------------------------  */
void printMatrix(char* title, int** Matrix, int N);

int startClient(void);

int** multiplyMatrix(int** M1, int** M2, int N);

int** initMatrix(int N);
