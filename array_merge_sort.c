
#include<stdio.h>
/*
void swapping(int &a, int &b) {     //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
*/
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      printf("%d ", array[i]);
   printf("\n");
}

void merge(int *array, int l, int m, int r) {
    int res[r+1];
    int i = l, j = m+1 , k = l;
    while (i <= m && j <= r) {
        if(array[i] <= array[j])
            res[k++] = array[i++];
        else
            res[k++] = array[j++];
    }
    // copy the remaining elements from 1st array to result array
    while (i <= m)
        res[k++] = array[i++];
    // copy the remaining elements from 2nd array to result array
    while (j <= r)
        res[k++] = array[j++];
    // copy the result array to original array
    for (int i = l; i <= r; i++)
        array[i] = res[i];
    display(res+l, k-l);
}

void mergeSort(int *array, int l, int r) {
    if (l == r)
        return;
    int m = l + ((r-l)/2);
    mergeSort(array, l, m);
    mergeSort(array, m+1, r);
    merge(array, l, m, r);
}

int main() {
   int n;
   int arr[] ={8,4,3,12,25,6,13,10};
   n =  sizeof(arr)/sizeof(arr[0]);
   mergeSort(arr, 0, n-1);     //(n-1) for last index
   printf ("Array after Sorting: ");
   display(arr, 8);
}

