#include <stdio.h>
  
void swap(int *a, int *b); 
  
void sort012(int a[], int arr_size) 
{
    int l = 0, m = 0, h = arr_size-1;
    while (m <= h) {
        if (a[m] == 2) {
            swap(&a[m], &a[h]);
            h--;
        } else if (a[m] == 0) {
            swap(&a[m], &a[l]);
            l++; m++;
        } else {
            m++;
        }
    }
} 
  
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void segregateArray(int array1[], int arr_size) 
{ 
    int i; 
    for (i = 0; i < arr_size; i++) 
        printf("%d ", array1[i]);
     printf("\n");
} 

int main() 
{ 
    int array1[] = {2, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1}; 
    int arr_size = sizeof(array1)/sizeof(array1[0]); 
    int i; 
  
    sort012(array1, arr_size); 
  
    printf ("segregated array : "); 
    segregateArray(array1, arr_size);  
    return 0; 
} 


/* Try more Inputs
case 1: 
actual = Sort012([0, 1, 2, 0, 1, 2],5)
expected = [0, 0, 1, 1, 2, 2]

case2: 
 actual = Sort012([0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1],11)
 expected = [0,0,0,0,0,1,1,1,1,1,2,2]
 
case3: 
actual = Sort012([2,0,1}],3)
expected = [0,1,2]
*/