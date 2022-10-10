#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP_SIZE (128)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

void insert_min_heap(int* min_heap, int min_index, int item)
{
    min_heap[min_index] = item;
    int root_index = (min_index-1)/2;
    while(min_index > 0) {
        if (min_heap[root_index]  < min_heap[min_index])
            break;
        int tmp = min_heap[root_index];
        min_heap[root_index] = min_heap[min_index];
        min_heap[min_index] = tmp;
        min_index = root_index;
        root_index = (min_index-1)/2;
    }
}

void insert_max_heap(int* max_heap, int max_index, int item)
{
    max_heap[max_index] =  item;
    int root_index = (max_index-1)/2;
    while (max_index > 0) {
        if (max_heap[root_index] > max_heap[max_index])
            break;
        int tmp = max_heap[root_index];
        max_heap[root_index] = max_heap[max_index];
        max_heap[max_index] = tmp;
        max_index = root_index;
        root_index = (max_index - 1)/2;
    }
}

void remove_min_heap(int *min_heap, int min_index)
{
    // swap root with the last item
    int tmp = min_heap[0];
    min_heap[0] = min_heap[min_index-1];
    min_heap[min_index-1] = tmp;
    min_index--;
    int root_index = 0;
    printf("min_heap(min_index %d): ", min_index);
    print_arr(min_heap, min_index);
    while (root_index < min_index) {
        int left_index = 2 * root_index + 1;
        int right_index = 2 * root_index + 2;
        if (right_index < min_index && min_heap[root_index] > min_heap[right_index]) {
            if (min_heap[left_index] < min_heap[right_index]) {
                int tmp = min_heap[root_index];
                min_heap[root_index] = min_heap[left_index];
                min_heap[left_index] = tmp;
                root_index = left_index;
            } else {
                int tmp = min_heap[root_index];
                min_heap[root_index] = min_heap[right_index];
                min_heap[right_index] = tmp;
                root_index = right_index;
            }
        } else if (left_index < min_index && min_heap[root_index] > min_heap[left_index]) {
            int tmp = min_heap[root_index];
            min_heap[root_index] = min_heap[left_index];
            min_heap[left_index] = tmp;
            root_index = left_index;
        } else {
            break;
        }
        printf("min_heap(min_index %d): ", min_index);
        print_arr(min_heap, min_index);
    }
}


void remove_max_heap(int *max_heap, int max_index)
{
    // swap root with the last item
    int tmp = max_heap[0];
    max_heap[0] = max_heap[max_index-1];
    max_heap[max_index-1] = tmp;
    max_index--;
    int root_index = 0;
    while (root_index < max_index) {
        int left_index = 2 * root_index + 1;
        int right_index = 2 * root_index + 2;
         if (right_index < max_index && max_heap[root_index] < max_heap[right_index]) {
            if (max_heap[left_index] > max_heap[right_index]) {
                int tmp = max_heap[root_index];
                max_heap[root_index] = max_heap[left_index];
                max_heap[left_index] = tmp;
                root_index = left_index;
            } else {
                int tmp = max_heap[root_index];
                max_heap[root_index] = max_heap[right_index];
                max_heap[right_index] = tmp;
                root_index = right_index;
            }
        } else if (left_index < max_index && max_heap[root_index] < max_heap[left_index]) {
            int tmp = max_heap[root_index];
            max_heap[root_index] = max_heap[left_index];
            max_heap[left_index] = tmp;
            root_index = left_index;
        } else {
            break;
        }
    }
}

void print_arr(int* arr, int size)
{
    for (int i = 0; i < size; i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

int get_median_from_heaps(int* min_heap, int min_index, int* max_heap, int max_index)
{
    int median = 0;
    int diff = ((max_index > min_index) ? (max_index - min_index) : (min_index - max_index));
    switch (diff) {
    case 0:
        median = (max_heap[0] + min_heap[0])/2;
        break;
    case 1:
        median = (max_index > min_index) ? max_heap[0] : min_heap[0];
        break;
    default:
        if (max_index > min_index) { // move the item from max_heap to min_heap
            remove_max_heap(max_heap, max_index);
            int item = max_heap[max_index-1];
            max_heap[max_index-1] = 0;
            max_index--;
            insert_min_heap(min_heap, min_index, item);
            min_index++;
        } else { // move the item from min_heap to max_heap
            remove_min_heap(min_heap, min_index);
            int item = min_heap[min_index-1];
            min_heap[min_index-1] = 0;
            min_index--;
            insert_max_heap(max_heap, max_index, item);
            max_index++;
        }
        printf("max_heap(max_index %d): ", max_index);
        print_arr(max_heap, max_index);
        printf("min_heap(min_index %d): ", min_index);
        print_arr(min_heap, min_index);
        return get_median_from_heaps(min_heap, min_index, max_heap, max_index);
    }
    return median;
}

int findMedian(int A[], int size)
{
    // create max heap array and min heap array
    int max_heap[size]; 
    int max_index = 0;
    int min_heap[size]; 
    int min_index = 0;
    int median = 0;
    memset(max_heap, 0, size);
    memset(min_heap, 0, size);
    // take first two elements of the array
    if (size == 2) {
        median = (A[0] + A[1])/2;
        return median;
    }
    if (A[0] > A[1]) {
        min_heap[min_index++] = A[0];
        max_heap[max_index++] = A[1];
    } else {
        max_heap[max_index++] = A[0];
        min_heap[min_index++] = A[1];
    }
    for (int i = 2; i < size; i++) {
        if (A[i] > max_heap[0]) {
            // insert the element in to the min_heap
            insert_min_heap(min_heap, min_index, A[i]);
            min_index++;
        } else {
            // insert the element in to max_heap
            insert_max_heap(max_heap, max_index, A[i]);
            max_index++;
        }
    }
    printf("max_heap(max_index %d): ", max_index);
    print_arr(max_heap, max_index);
    printf("min_heap(min_index %d): ", min_index);
    print_arr(min_heap, min_index);
    median = get_median_from_heaps(min_heap, min_index, max_heap, max_index);
    return median;
}

int main(){
   int A[] = {12,4,5,3,8,7};
   int size = ARRAY_SIZE(A);
   printf ("Median: %d\n", findMedian(A, size));
   return 0;
}