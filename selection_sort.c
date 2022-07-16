#include  <stdio.h>

// scan the entire array to find the smallest number's index till the end of array 
// Once reach end of array, put/swap the smallest number to top of the array
// continue to scan for next smallest number in the sub-array array+1;
int* selection_sort(int* a, int size) 
{
    if (!a)
        return NULL;
    
    for (int i = 0; i < size; i++){
        int min_index = i;
        for (int j = i+1; j < size; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        //swap a[i] and a[min_index]
        int tmp = 0;
        tmp = a[i]; a[i] = a[min_index]; a[min_index] = tmp;
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
    selection_sort(a, size);
    printf("\nSorted array:");
    for (int i = 0; i < size; i++) 
       printf("%d ", a[i]); 
    return 0;
}