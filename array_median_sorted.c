#include  <stdio.h>

/* This function returns median 
   of array1[] and array2[].
Assumptions in this function:
    Both array1[] and array2[] are 
    sorted arrays
    Both have n elements */
int get_median(int arr1[], int arr2[], int len)
{
    int median = 0;
    if (len == 2) {
        int m1 = (arr1[0] > arr2[0]) ? arr1[0] : arr2[0];
        int m2 = (arr1[1] < arr2[1]) ? arr1[1] : arr2[1];
        median = (m1+m2)/2;
        printf("m1 %d m2 %d\n", m1, m2);
        return median;
    }
    
    int m1 = arr1[len/2];
    int m2 = arr2[len/2];
    if (m1 > m2) {
        median = get_median(arr1, (arr2+(len/2)), len/2+1);
    } else {
        median = get_median((arr1+(len/2)), arr2, len/2+1);
    }
    return median;
}

int main()
{
  // int array1[] = {1, 6, 8, 10, 12};
  //int array2[] = {2, 3, 4, 9, 11};
  //  int array1[] = {1,2,3,6};
  //  int array2[] = {4,6,8,10};
  //  int array1[] = {2, 7};
  //  int array2[] = {11, 16};
     int array1[] = {1, 2};
   int array2[] = {3, 4};

    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    if (size1 == size2)
        printf("Median is %d\n", get_median(array1, array2, size1));
    return 0;
}

/* Try more Inputs

case1: 
 actual = getMedian([0,0],[0,0],2)
 expected = 0
 
case2: 
actual = getMedian([2,7],[11,16],2)
expected = 9

case3: 
actual = getMedian([1,2,3,6],[4,6,8,10],4)
expected = 5
*/