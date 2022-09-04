//gcc 7.4.0

#include  <stdio.h>
#include <stdbool.h>

#define M 4
#define N 4

int findRowIndex(bool mat[][N])
{
    int min_col = N-1;
    int max_row = -1;
    for (int row = 0; row < M; row++) {
        if (mat[row][min_col] == 0){
            printf("skip row %d as mat[%d][%d] = %d\n", row, row, min_col, mat[row][min_col]);
            continue;
        }
        max_row = row;
        // binary search for mincol in current row
        int start = 0, end = min_col-1;
        printf("binary search in row %d min_col %d start %d end %d\n", row, min_col, start, end);
        while (start <= end) {
            int mid = (start+end)/2;
            if (mat[row][mid] == 0) {
                start = mid+1;
            } else {
                min_col = mid;
                end = mid-1;
            }
        }
        printf("max_row %d min_col %d\n", max_row, min_col);
        if (min_col == 0) {
            printf("stop further search found max_row %d min_col %d\n", max_row, min_col);
            break;
        }
        min_col--;
    }
    return max_row+1;
}

int main()
{
	/*bool mat[M][N] =
	{
		{ 0, 0, 1, 1, 1 },
		{ 0, 0, 1, 1, 1 },
		{ 0, 0, 1, 1, 1 },
		{ 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 1 }
	};*/
    
    /*bool mat[M][N] =
	{
		{ 1, 1, 1 },
		{ 0, 0, 0 },
		{ 1, 1, 0 },
        { 1, 0, 0 }, 
	};*/
    bool mat[M][N] =
	{
        { 0, 1, 1, 1 },
		{ 0, 0, 1, 1 },
		{ 1, 1, 1, 1 },
        { 0, 0, 0, 0 }, 
    };

	int rowIndex = findRowIndex(mat);

	// rowIndex = 0 means no 1's are present in the matrix
	if (rowIndex)
		printf("Maximum 1's are present in the row %d\n", rowIndex);

	return 0;
}
/* Try more Inputs
case1:
 actual = findRow(
      [[0, 1, 1, 1], 
       [0, 0, 1, 1], 
       [1, 1, 1, 1], 
       [0, 0, 0, 0]])
expected = 2

case2:
actual = findRow(
      [[1, 1, 1], 
       [0, 0, 0], 
       [1, 1, 0], 
       [1, 0, 0]])
expected = 0

case3:
actual = findRow(
      [[0, 0, 0, 1, 1], 
       [0, 0, 1, 1, 1], 
       [0, 0, 0, 0, 0], 
       [0, 1, 1, 1, 1],
       [0, 0, 0, 0, 1]])
expected = 4

*/