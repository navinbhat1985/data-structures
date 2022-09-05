#include  <stdio.h>

void printarr(int* arr, int n) 
{
    for (int i = 0; i < n ; i++)
        printf("%2d ", arr[i]);
    printf("\n");
}
int merge(int* arr, int l, int m, int r) 
{
    int inv_cnt = 0;
    int res[r+1];
    int i = l, j = m+1, k = l;
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            res[k++] = arr[i++];
        } else {
            res[k++] = arr[j++];
            inv_cnt++;
            printf("3 inv_cnt = %d\n", inv_cnt);
        }
    }
    while (i <= m)
        res[k++] = arr[i++];
    while (j <= r)
        res[k++] = arr[j++];
    for (int i = l; i <= r ;i++)
        arr[i] = res[i];
    return inv_cnt;
}

int count_swaps(int* arr, int l, int m, int r)
{
    int swaps = 0;
    int i = l, j = m+1;
    while (i <= m && j <= r) {
        if (arr[i] > arr[j]) {
            swaps = m+1-i;
            break;
        } else {
            i++;
        }
    }
    return swaps;
    
}
int merge_sort(int* arr, int l, int r)
{
    int inv_cnt = 0;
    if (l == r)
        return 0;
    int m = l + ((r-l)/2);
    inv_cnt += merge_sort(arr, l, m);
    //printf("1 inv_cnt = %d\n", inv_cnt);
    inv_cnt += merge_sort(arr, m+1, r);
    //printf("2 inv_cnt = %d\n", inv_cnt);
    //inv_cnt += merge(arr, l, m, r);
    inv_cnt += count_swaps(arr, l, m, r);
    //printf("4 inv_cnt = %d\n", inv_cnt);
    return inv_cnt;
}

int arrayInversion(int array1[], int n) {
    return merge_sort(array1, 0, n-1);
}

int main() {
   //int array1[] = {3, 2 , 1};
   // int array1[] = {9, 1, 6, 4, 5};
   // int array1[] = {4, 1, 3, 2};
     int array1[] = {8,4,2,1};
   int n = sizeof(array1)/sizeof(array1[0]);
    printarr(array1, n);
   printf("Number of inversions are %d\n", arrayInversion(array1, n));
     printarr(array1, n);
}


/* Try more Inputs
case 1: 
actual = arrayInversion([3, 2, 1],3)
expected = 3

case2: 
 actual = arrayInversion([4, 1, 3, 2],4)
 expected = 4
 
case3: 
actual = arrayInversion([8, 4, 2, 1],4)
expected = 6
*/

