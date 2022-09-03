//gcc 7.4.0

#include  <stdio.h>

int find_once_item(int* arr, int n)
{
    int xor_sum = arr[0];
    for (int i = 1; i < n; i++) {
        xor_sum ^= arr[i];
    }
    return xor_sum;
}

int main(void)
{
    //int arr[] = {2,2,1};
    //int arr[] = {4,1,2,1,2};
    //int arr[] = {-1,2,-1,3,2};
    //int arr[] = {9,4,9,6,4};
    int arr[] = {1,1,2,2,3,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Element occuring once is %d\n", find_once_item(arr, n));
    return 0;
}

/* Try more Inputs
Input: [2,2,1]
Input: [4,1,2,1,2]

case 1: 
actual = main([-1,2,-1,3,2])
expected = 3

case2: 
 actual = main([9,4,9,6,4])
 expected = 6
 
case3: 
actual = main([1,1,2,2,3,3,4])
expected = 4
*/