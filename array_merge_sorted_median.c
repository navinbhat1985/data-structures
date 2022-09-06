//gcc 7.4.0

#include  <stdio.h>
 
/* This function returns median 
   of array1[] and array2[].
Assumptions in this function:
    Both array1[] and array2[] are 
    sorted arrays
    Both have n elements */
int getMedian(int a1[], 
              int a2[], int len)
{
    int m = (len-1);
    int median = 0;
    int i = 0, j = 0, k = 0, item = 0;
    while (i <= len && j <= len) {
        if (a1[i] <= a2[j]) {
            item = a1[i]; i++;
        } else {
            item = a2[j]; j++;
        }
        printf("%2d ", item);
        if (k == m) {
            median = item;
        } else if (k == m+1) {
            median += item;
            median/=2;
            break;
        }
        k++;
    }
    printf("\n");
    return median;
}


int main()
{
    int array1[] = {1, 6, 8, 10, 12};
    int array2[] = {2, 3, 4, 9, 11};
   // int array1[] = {1,2,3,6};
   // int array2[] = {4,6,8,10};
    //int array1[] = {2, 7};
    //int array2[] = {11, 16};
    // int array1[] = {1, 2};
   //int array2[] = {3, 4};
    int size1 = sizeof(array1) / 
             sizeof(array1[0]);
    int size2 = sizeof(array2) / 
             sizeof(array2[0]);
    if (size1 == size2)
        printf ("Median is %d\n", getMedian(array1, array2, size1));

    return 0;
}
