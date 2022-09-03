#include <stdio.h>

// Function to find contiguous sub-array with the largest sum
// in given set of integers
int kadane(int arr[], int n)
{
    int result_sum = arr[0];
    int intermediate_sum = arr[0];
    for (int i = 1; i < n; i++) {
        intermediate_sum += arr[i];
        if (arr[i] > intermediate_sum) {
            intermediate_sum = arr[i];
        }
        if (intermediate_sum > result_sum)
            result_sum = intermediate_sum;
    }
	return result_sum;
}

int main()
{
	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    //int arr[] = {1};
    //int arr[] = {-4, 2, -5, 1, 2, 3, 6, -5, 1};
    //int arr[] = {-5, 6, -7, 1, 4, -8, 16};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("The sum of contiguous sub-array with the largest sum is %d\n", kadane(arr, n));
	return 0;
}

/* Try more Inputs

case1:
actual = maxSubArraySum([-2,1,-3,4,-1,2,1,-5,4],9)
expected = 6

case2:
actual = maxSubArraySum([1],1)
expected = 1

case3:
actual = maxSubArraySum([-4, 2, -5, 1, 2, 3, 6, -5, 1],9)
expected = 12

case4:
actual = maxSubArraySum([-5, 6, -7, 1, 4, -8, 16],7)
expected = 16

*/