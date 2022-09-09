//gcc 7.4.0

#include  <stdio.h>
  
// Returns minimum number of jumps 
// to reach array1[n-1] from array1[0] 
int minJumpToReachEnd(int a[], int n) 
{
    int jumps = 1;
    int x = a[0];
    int y = a[0];
    
    for (int i = 1; i < n; i++) {
        if (x >= n-i-1)
            return jumps;
        x--;
        y--;
        if (a[i] > y) {
            y = a[i];
        }
        if (x == 0) {
            jumps++;
            x = y;
        }
        
    }
    return jumps; 
} 

int main() 
{ 
    int array1[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    //int array1[] ={3,2,1,0,4};
    //int array1[] = { 2,3,1,1,4 }; 
    //int array1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int size = sizeof(array1) / sizeof(int); 
  
    printf("Jumps: %d " , minJumpToReachEnd(array1, size)); 
    return 0; 
} 
