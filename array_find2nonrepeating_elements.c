#include <stdio.h>

void find2Element(int arr[], int n)
{
    int xor = arr[0];
    int first = 0, second = 0;
    for (int i = 1; i < n; i++)
        xor ^= arr[i];
    int mask = xor & ~(xor-1);
    printf("mask = 0x%x\n", mask);
    for (int i = 0; i < n; i++) {
        if (arr[i] & mask) {
            first ^= arr[i];
        } else {
            second ^= arr[i];
        }
    }
    printf("elements are %d and %d", first, second);
	return 0;
}

// Find two duplicate elements in a limited range array
int main()
{
	//int arr[] = { 2,4,7,9,2,4 };
    //int arr[] = {4,5,4,5,3,2,9,3,9,8};
    int arr[] = {1,1,2,2,3,3,4,5,5,6,7,7};
    int n = sizeof(arr)/sizeof(arr[0]);
	find2Element(arr, n);
	return 0;
}

/* Try more Inputs
case1:
actual = find2Element([2,4,7,9,2,4])
expected = 7,9

case2:
actual = find2Element([4,5,4,5,3,2,9,3,9,8])
expected = 2,8

case3:
actual = find2Element([1,1,2,2,3,3,4,5,5,6,7,7])
expected = 6,4
*/