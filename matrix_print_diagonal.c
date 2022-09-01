#include <stdio.h>
#define M 5
#define N 5

void printAllDgl(int matrix[M][N])
{
    for (int k = 0; k < M; k++) {
        int i = k;
        int j = 0;
        while (i >= 0) {
            printf("%2d ", matrix[i][j]);
            i = i - 1;
            j = j + 1;
        }
    }
    for (int k = 1; k < N; k++) {
        int i = N - 1;
        int j = k;
        while (j < N) {
            printf("%2d ", matrix[i][j]);
            i = i - 1;
            j = j + 1;
        }
    }
}

/* Try more Inputs
case 1: 
actual = spiralPrint(3,3,[[1,2,3],[4,5,6],[7,8,9]])
expected = [[1,2,3,6,9,8,7,4,5]]

case2: 
 actual = spiralPrint(3,4,[[1,2,3,4],[5,6,7,8],[9,10,11,12]])
 expected = [1,2,3,4,8,12,11,10,9,5,6,7]
 
*/
int main()
{
    int matrix[M][N] =
	{
		{ 1,  2,  3,  4, 5},
		{16, 17, 18, 19, 6},
		{15, 24, 25, 20, 7},
		{14, 23, 22, 21, 8},
		{13, 12, 11, 10, 9}
	};
/*
    int matrix[M][N] =
	{
		{ 1, 2, 3},
		{ 4, 5, 6},
		{ 7, 8, 9},
    };*/

 /*   int matrix[M][N] =
	{
		{ 1, 2, 3,  4},
		{ 5, 6, 7,  8},
		{ 9, 10, 11, 12},
    };*/
	int top = 0, bottom = M - 1;
	int left = 0, right = N - 1;

    printAllDgl(matrix);
	return 0;
}
