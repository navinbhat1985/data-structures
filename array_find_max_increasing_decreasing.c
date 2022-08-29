
#include <stdio.h>

int findMaximumValue(int array1[], int low, int high)  
{
    /* array has only 1 element */
    if (low == high)
        return array1[low];
    
    /* array has only 2 elements */
    if (low+1 == high) {
        if (array1[low] >= array1[high])
            return array1[low];
        else
            return array1[high];
    }
    int mid = low + (high-low)/2;
    
    if (array1[mid] >= array1[mid-1] && array1[mid] >= array1[mid+1])
        return array1[mid];
    if (array1[mid] >= array1[mid-1] && array1[mid] < array1[mid+1])
        return findMaximumValue(array1, mid+1, high);
    else 
       return findMaximumValue(array1, low, mid-1);
        
}  

int main()  
{  
    int array1[] = {1, 3, 50, 10, 9, 7, 6};  
    int n = sizeof(array1)/sizeof(array1[0]);  
    printf ("The maximum Value  is %d" , findMaximumValue(array1, 0, n-1));  
    return 0;  
} 

/* Try more Inputs
case 1: 
actual = findMaximum([8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1],0,10)
expected = 500

case2: 
 actual = findMaximum([10, 20, 30, 40, 50],0,4)
 expected = 50
 
case3: 
actual = findMaximum([120, 100, 80, 20, 0],0,4)
expected = 120
*/