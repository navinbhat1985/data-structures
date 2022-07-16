#include  <stdio.h>


// pick an item in the array[1..n] and look where to insert it to the left of it i.e in the array[0.. n-1]
// i.e find the right spot for the item picked at i to be placed in the left array[0..i-1]
// repeat the process until end of array
int* insertion_sort(int* a, int size) 
{
    if (!a)
        return NULL;
    
    for (int i = 1; i < size; i++) {
        // item to compare
        int item = a[i];
        // initialize insertion index to i
        int insert_index = i;
        // loop through the left array
        for (int j = i-1; j >= 0; j--) {
            // check if item is less than the a[j]
            // if yes, then j is the new insertion index
            if (item < a[j]) {
                // move the a[j] to insertion_index
                a[insert_index] = a[j];
                // update the insertion index to j
                insert_index = j;
            }
        }
        // insert the item in to insertion_index
        a[insert_index] = item;
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
    insertion_sort(a, size);
    printf("\nSorted array:");
    for (int i = 0; i < size; i++) 
       printf("%d ", a[i]); 
    return 0;
}
