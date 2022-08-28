#include <stdio.h>

// Recursive implementation of Binary Search Algorithm to return
// the position of target x in the sub-array array[low..high]
int binarySearch(int array[], int low, int high, int key)
{
    if ( low > high )
        return -1;
    int mid = low + ((high - low)/2);
    if (array[mid] == key) {
        return mid;
    } else if (key < array[mid]) {
        return binarySearch(array, low, mid, key);
    } else {
        return binarySearch(array, mid+1, high, key);
    }
}
 
// Recursive implementation of Binary Search Algorithm
int main(void)
{
    int array[] = { 2, 5, 6, 8, 9, 10 };
    int target = 9;
 
    int n = sizeof(array)/sizeof(array[0]);
 
    int low = 0, high = n - 1;
    int index = binarySearch(array, low, high, target);
 
    if (index != -1)
        printf("Element found at index %d", index);
    else
        printf("Element not found in the array");
 
    return 0;
}
