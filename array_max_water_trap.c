//gcc 7.4.0

#include  <stdio.h>
#include <stdbool.h>

  
int storeWater(int arr[], int n) 
{ 
    int max_right[n];
    int max_left[n];
    int max_water[n];
    int total_water = 0;
    max_right[n-1] = arr[n-1];
    int max_idx = n-1;
    //printf("\nmax_right array:\t");
    for (int i = n-1; i >= 0; i--) {
        if (arr[i] > arr[max_idx]) {
            max_right[i] = arr[i];
            max_idx = i;
        } else {
            max_right[i] = arr[max_idx];
        }
        //printf("%2d ", max_right[i]);
    }
    max_left[0] = arr[0];
    max_idx = 0;
    //printf("\nmax_left array:\t");
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[max_idx]) {
            max_left[i] = arr[i];
            max_idx = i;
        } else {
            max_left[i] = arr[max_idx];
        }
        //printf("%2d ", max_left[i]);
    }
    //printf("\nmax_water array:\t");
    for (int i = 1; i < n-1; i++) {
        if (max_left[i] > max_right[i]) {
            max_water[i] = max_right[i] - arr[i];
        } else {
            max_water[i] = max_left[i] - arr[i];
        }
        total_water += max_water[i];
        //printf("tower%d %2d ", i, max_water[i]);
    }
    return total_water;
} 
  
int main() 
{ 
    //int array1[] = { 5,3,4,6,3,6 }; 
    int array1[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(array1) / sizeof(array1[0]);
    printf("tower array:\t");
    for (int i = 0; i < n; i++)
        printf("%2d ", array1[i]);
    printf("\nMaximum water that can be stored is %d\n", storeWater(array1, n)); 
    return 0; 
}