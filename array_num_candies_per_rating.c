//gcc 7.4.0

#include  <stdio.h>

int num_candies (int a[], int n)
{
    int candies[n];
    candies[0] = 1;
    int num_candies = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1])
            candies[i] = candies[i-1] + 1;
        else
            candies[i] = 1;
    }
    for (int i = n-2; i >=0; i--) {
        if (a[i] > a[i+1] && candies[i] <= candies[i+1]) {
            candies[i] = candies[i+1] + 1;
        } 
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", candies[i]);
        num_candies += candies[i];
    }
    printf("\nnum_candies %d\n", num_candies);
        
    return num_candies;
}

int main(void)
{
    //int arr[] = {7, 5, 7, 1};
    int arr[] = {1, 3, 4, 5, 2};
    //int arr[] = {1, 5, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");
    num_candies(arr, n);
    return 0;
}