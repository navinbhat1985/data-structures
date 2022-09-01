#include <stdio.h>

int majorityElement(int arr[], int n)
{
    int majority = arr[0];
    int count = 1;
    for (int i = 1; i < n; i++) {
        
        if (arr[i] == majority) {
            count++;
        } else {
            count--;
            if (count == 0) {
                printf("majority number changed from %d to %d\n", majority, arr[i]);
                majority = arr[i];
                count = 1;
            }
        }
        printf("majority %d count %d\n", majority, count);
    }
    return majority;
}
 
int main(void)
{
    int arr[] = { 3, 8, 3, 3, 1, 2, 2, 2, 2, 2, 2 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Majority element is %d", majorityElement(arr, n));
    return 0;
}