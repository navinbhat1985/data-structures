#include<stdio.h>
int findElement(int arr[], int n) 
{
    int left_max[n];
    /* store max at each index to the left */
    int max = arr[0];
    printf("   ");
    for (int i = 1; i < n; i++) {
        if (arr[i-1] > max) {
            left_max[i] = max = arr[i-1];
        } else {
            left_max[i] = max;
        }
        printf("%2d ", left_max[i]);
    }
    printf("\n");
    /* traverse the array from right to left */
    int right_min = arr[n-1];
    for (int i = n-2; i >= 1; i--) {
        printf("arr[%d] %d right_min %d left_max[%d] %d\n", i, arr[i], right_min, i, left_max[i]);
        if (arr[i] < right_min && arr[i] > left_max[i])
            return i;
        if (arr[i] < right_min)
            right_min = arr[i];
        
    }
    printf("\n");
    return -1; 
} 
  

int main() 
{ 
    int arr[] = {5, 1, 4, 3, 6, 8, 10, 7, 9}; 
    int n = sizeof arr / sizeof arr[0];
    for (int i = 0; i < n ; i++)
        printf("%2d ", arr[i]);
    printf("\n");
    int index = findElement(arr, n);
    printf("Index of the element is %d and element %d\n", index, arr[index]); 
    return 0; 
}
/* Try more Inputs

findElement(array, length_of_array)


case1: 
actual = findElement([5, 1, 4, 3, 6, 8, 10, 7, 9],9)
expected = 4

case2: 
actual = findElement([6, 2, 5, 4, 7, 9, 11, 8, 10],9)
expected = 4

case3:
actual = findElement([5, 1, 4, 4],4)
expected = -1

*/