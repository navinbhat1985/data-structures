//gcc 7.4.0

#include  <stdio.h>

void remove_duplicates(int* a, int sz)
{
    int i = 0, j = 0;
    while (j < sz) {
        if (a[i] == a[j]) {
            j++;
        } else {
            a[++i] = a[j];
        }
    }
    int new_sz = i+1;
    for (int k = 0; k < new_sz; k++)
        printf("%d ", a[k]);
}


int main(void)
{
    int arr[] = {0,0,0,1,1,1,1,2,3,3};
    int sz = sizeof(arr)/sizeof(arr[0]);
    remove_duplicates(arr, sz);                    
    return 0;
}