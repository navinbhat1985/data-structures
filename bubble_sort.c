//gcc 7.4.0

#include  <stdio.h>

// bubble sort is similar to putting pebble in a container of water
// the heavy/larger element/pebble goes to the bottom(index size-1) of the array after each iteration
// repeat the process to put the next larger element to the bottom (index size-2) and so on
int* bubble_sort(int* a, int size)
{
    if (!a)
        return NULL;
    int tmp = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-i-1; j++) {
            // compare each element with its adjacent
            if (a[j] > a[j+1]) {
                // swap the elements if a[j] > a[j+1}
                tmp = a[j]; a[j] = a[j+1]; a[j+1] = tmp;
            }
        }
    }
    return a;
}


int main(void)
{
    int a[10] = {6,5,3,1,8,7,2,4,0, -1};
    int size = sizeof(a)/sizeof(a[0]);
    printf("\nOriginal array:");
    for (int i = 0; i < size; i++) 
       printf("%d ", a[i]); 
    bubble_sort(a, size);
    printf("\nSorted array:");
    for (int i = 0; i < size; i++) 
       printf("%d ", a[i]); 
    return 0;
}
