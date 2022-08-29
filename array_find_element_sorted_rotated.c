#include <stdio.h>

// Function to find an element x in a circularly sorted array
int arraySearch(int array[], int start, int end, int val)
{
    if (start > end)
        return -1;
    
    int mid = start + (end - start)/2;
    if (array[mid] == val)
        return mid;
    
    if (array[mid] >= array[start]) {
        if (val >= array[start] && val <= array[mid])
            return arraySearch(array, start, mid-1, val);
        return arraySearch(array, mid+1, end, val);
    }
    
    if (val >= array[mid] & val <= array[end]) 
        return arraySearch(array, mid+1, end, val);
    return arraySearch(array, start, mid-1, val);
        
	return -1;
}

int main(void)
{
	int array1[] = {9, 10, 2, 5, 6, 8};
	int target = 5;

	int n = sizeof(array1)/sizeof(array1[0]);
	int index = arraySearch(array1, 0, n-1, target);

	if (index != -1)
		printf("Element found at index %d", index);
	else
		printf("Element not found in the array");

	return 0;
}
/* Try more Inputs
case 1: 
actual = arraySearch([3, 4, 5, 6, 7, 8, 9, 10, 1, 2],9,1)
expected = 8

case2: 
 actual = arraySearch([5, 6, 7, 8, 9, 10, 1, 2, 3],8,3)
 expected = 8
 
case3: 
actual = arraySearch([5, 6, 7, 8, 9, 10, 1, 2, 3],8,28)
expected = -1

case4:
actual = arraySearch([30, 40, 50, 10, 20],4,10)
expected = 3

*/