#include<stdio.h>

int randomPartition(int array1[], int l, int r); 
  
void printarr(int *arr, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++) 
        printf("%2d ", arr[i]);
    printf("\n");
}
// This function returns k'th smallest element in array1[l..r] using  
int findKthSmallest(int arr[], int l, int r, int k) 
{ 
    int i, j, pivot = r;
    if ( k-1 < l || k-1 > r)
        return -1;
    
    for (i = l, j = l; i < r; i++) {
        if (arr[j] < arr[pivot]) {
            j++; continue;
        }
        if (arr[i] < arr[pivot]) {
            if (i != j) {
                // swap arr[i] and arr[j]
                arr[j] ^= arr[i];
                arr[i] ^= arr[j];
                arr[j] ^= arr[i];
            }
            j++;
        }
    }
    //printf("i %d j %d pivot %d\n",i,j, pivot);
    // swap arr[j] and arr[pivot]
    if (j != pivot) {
        arr[j] ^= arr[pivot];
        arr[pivot] ^= arr[j];
        arr[j] ^= arr[pivot];
    }
    //printarr(arr, r-l+1);
    if (k-1 < j) {
        return findKthSmallest(arr, l, j-1, k);
    } else if (k-1 > j){
        return findKthSmallest(arr, j+1, r, k);
    } else {
        return arr[j];
    }
} 
  
  
int main() 
{ 
    int array1[] = {54, 26, 93, 17, 77, 31, 44,20,55}, k = 3; 
    //int array1[] = {7, 10, 4, 3, 20, 15}, k = 3; 
    //int array1[] = {7, 10, 4, 3, 20, 15}, k = 4; 
    //int array1[] = {12, 3, 5, 7, 19}, k = 5; 
    int n = sizeof(array1)/sizeof(array1[0]); 
    printarr(array1, n);
    printf("\nK'th(%d'th) smallest element is %d\n", k, findKthSmallest(array1, 0, n-1, k)); 
    return 0; 
}


/* Try more Inputs
case 1: 
actual = findKthElement([7, 10, 4, 3, 20, 15],0,5,3)
expected = 7

case2: 
 actual = findKthElement([7, 10, 4, 3, 20, 15],0,5,4)
 expected = 10
 
case3: 
actual = findKthElement([12, 3, 5, 7, 19],0,4,2)
expected = 5
*/
