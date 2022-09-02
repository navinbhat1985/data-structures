#include <stdio.h>
  
#define N 4 
  
/* Function to rotate the matrix 90 degree clockwise 
Generalized logic: SRC[x][y]=>DEST[y][N-1-x]

matrix[i][j]=> matrix[j][N-1-i]
matrix[j][N-1-i] => matrix[N-1-i][N-1-j]
matrix[N-1-i][N-1-j]=>matrix[N-1-j][i]
matrix[N-1-j][i]=>matrix[i][j]
*/  
void matrixRotation(int matrix[N][N]) 
{ 
    for (int i = 0; i < N/2; i++) {
        for ( int j = i; j < (N-i-1); j++) {
            int tmp = matrix[j][N-1-i];
            matrix[j][N-1-i] = matrix[i][j];
            matrix[i][j] = matrix[N-1-j][i];
            matrix[N-1-j][i] = matrix[N-1-i][N-1-j];
            matrix[N-1-i][N-1-j] = tmp;
        }
    }
}

/* Function to rotate the matrix 90 degree anti-clockwise 
Generalized logic: SRC[x][y]=>DEST[N-1-y][x]

matrix[i][j] => matrix[N-1-j][i]
matrix[N-1-j][i] => matrix[N-1-i][N-1-j]
matrix[N-1-i][N-1-j] => matrix[j][N-1-i]
matrix[j][N-1-i] => matrix[i][j]
*/  
void matrixRotation_anticlock(int matrix[N][N]) 
{
    for (int i = 0; i < N/2; i++) {
        for (int j = i; j < N-i-1; j++) {
            int tmp = matrix[N-1-j][i];
            matrix[N-1-j][i] = matrix[i][j];
            matrix[i][j] = matrix[j][N-1-i];
            matrix[j][N-1-i] = matrix[N-1-i][N-1-j];
            matrix[N-1-i][N-1-j] = tmp;
        }
    }
}  

void printMatrix(int matrix[N][N]) 
{ 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) 
            printf ("%3d ", matrix[i][j]); 
        printf("\n"); 
    } 
} 
  

int main() 
{ 
    int matrix[N][N] = { { 1, 2, 3, 4 }, 
                      { 5, 6, 7, 8 }, 
                      { 9, 10, 11, 12 }, 
                      { 13, 14, 15, 16 } }; 
    printf("Original matrix:\n");
    printMatrix(matrix); 
    matrixRotation(matrix); 
    printf("Matrix 90 degree clockwise rotated:\n");
    printMatrix(matrix); 
    printf("Matrix 90 degree anti-clockwise rotated:\n");
    matrixRotation_anticlock(matrix);
    printMatrix(matrix);
    return 0; 
} 

/* Try more Inputs
case 1: 
int matrix[][] = { { 1, 2, 3}, 
                   { 4, 5, 6}, 
                   { 7, 8, 9}}; 

actual = matrixRotation(matrix)
expected = 7  4  1 
           8  5  2 
           9  6  3
*/
