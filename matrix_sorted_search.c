//gcc 7.4.0

#include  <stdio.h>

int search(int mat[4][4], int n, int x) 
{
    int i = 0, j = n-1;
    while (i >=0 && i < n && j >= 0 && j < n){
        printf("Look for %d at mat[%d][%d] = %d\n", x, i, j, mat[i][j]);
        if (mat[i][j] == x) { // if mat[i][j] == x, found the item, print i,j and break;
            printf("Found %d at mat[%d][%d]\n", x, i, j);
            return 0;
        } else if (mat[i][j] < x) { // if mat[i][j] < x, move down i.e i++
            i++;
        } else { // if mat[i][j] > x, move left i.e j--
            j--;
        }
    }
    printf("Element %d is not found in matrix\n", x);
    return 0;  
} 
   

int main() 
{ 
    int mat[4][4] = { { 10, 20, 30, 40 }, 
                      { 15, 25, 35, 45 }, 
                      { 27, 29, 37, 48 }, 
                      { 32, 33, 39, 50 } }; 
    search(mat, 4, 29); 
    search(mat, 4, 32);
    search(mat, 4, 59);
   
    return 0; 
} 

/* Try more Inputs

case1:
 actual = searchElement([[10, 20, 30, 40], 
		[15, 25, 36, 46], 
		[27, 29, 37, 48],
		[32, 33, 39, 50]],4,32)
 expected = True
 
case2:
actual = searchElement([[10, 20, 30, 40],
		[15, 25, 36, 46], 
		[27, 29, 37, 48], 
		[32, 33, 39, 50]],4,59)
expected = False

*/