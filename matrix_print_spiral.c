#include <stdio.h>
#define M 3
#define N 3

void printSpiral(int matrix[][N], int top, int bottom, int left, int right)
{
    while (top <= bottom || left <= right) {
        int i = top;
        int j = 0;
        for (j = left; j < right; j++)
            printf("%2d ", matrix[i][j]);

        j = right;
        for (i = top; i < bottom; i++)
            printf("%2d ", matrix[i][j]);
        
        i = bottom;
        for (j = right; j > left; j--)
            printf("%2d ", matrix[i][j]);
        
        j = left;
        for (i = bottom; i > top; i--)
            printf("%2d ", matrix[i][j]);
        top++; bottom--;left++; right--;
        if (top == bottom && right == left)
            printf("%2d ", matrix[top][right]);
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
 /*   int matrix[M][N] =
	{
		{ 1,  2,  3,  4, 5},
		{16, 17, 18, 19, 6},
		{15, 24, 25, 20, 7},
		{14, 23, 22, 21, 8},
		{13, 12, 11, 10, 9}
	};*/

    int matrix[M][N] =
	{
		{ 1, 2, 3},
		{ 4, 5, 6},
		{ 7, 8, 9},
    };

 /*   int matrix[M][N] =
	{
		{ 1, 2, 3,  4},
		{ 5, 6, 7,  8},
		{ 9, 10, 11, 12},
    };*/
	int top = 0, bottom = M - 1;
	int left = 0, right = N - 1;

	printSpiral(matrix, top, bottom, left, right);

	return 0;
}

/* Try more Inputs
case 1: 
actual = spiralPrint(3,3,[[1,2,3],[4,5,6],[7,8,9]])
expected = [[1,2,3,6,9,8,7,4,5]]

case2: 
 actual = spiralPrint(3,4,[[1,2,3,4],[5,6,7,8],[9,10,11,12]])
 expected = [1,2,3,4,8,12,11,10,9,5,6,7]
 
*/