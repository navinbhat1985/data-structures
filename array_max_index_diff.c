//gcc 7.4.0

#include  <stdio.h>

void printarr(int* arr, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%2d ", arr[i]);
    }
    printf("\n");
}
int maxDiff(int arr[], int n) {
    int right[n];
    int left[n];
    right[n-1] = n-1;
    for (int i = n-2; i >= 0; i--) {
        right[i] = (arr[i] > arr[right[i+1]]) ? i : right[i+1];
    }
    printarr(right,n);
    left[0] = 0;
    for (int i = 1; i < n; i++) {
        left[i] = (arr[i] < arr[left[i-1]]) ? i : left[i-1];
    }
    printarr(left,n);
    
    int i = 0, j = 0, max_diff = -1;
    while (i < n && j < n) {
        if (arr[right[j]] >= arr[left[i]]) {
            int cur_diff = right[j] - left[i];
            max_diff = (cur_diff > max_diff) ? cur_diff : max_diff;
            j++;
        } else { 
            i++;
        }
    }
    return max_diff;
}
int main() {
  // int array[] = { 5, 7, 1, 2 };
    int array[] = {35, 9, 12, 3, 2, 70, 31, 33, 1};
   int n = sizeof(array) / sizeof(array[0]);
    printarr(array,n);
   printf("The maximum value of |arr[i] - arr[j]| + |i-j| is %d\n", maxDiff(array, n));
   return 0;
}
/* Try more Inputs
case1:
actual = findDiff([35, 9, 12, 3, 2, 70, 31, 33, 1])
expected = 6

case2:
actual = findDiff([1, 2, 3, 4, 5, 6])
expected = 5

case3:
actual = findDiff([9, 2, 3, 4, 5, 6, 7, 8, 18, 0])
expected = 8

case4:
actual = findDiff([6, 5, 4, 3, 2, 1])
expected = -1

*/