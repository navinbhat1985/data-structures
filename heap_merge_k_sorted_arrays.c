#include<stdio.h>
#include<stdlib.h>
#include<string.h>
  
#define n 4
  
// A min-heap node 
typedef struct mh_node 
{ 
    int i; 
    int j; 
    int val; 
}mh_node; 

void printarr(int arr[], int size) 
{ 
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
} 

void percolate_up_min_heap(mh_node* min_heap, int min_index)
{
    int root_index = (min_index - 1)/2;
    while (min_index > 0) {
        if (min_heap[min_index].val  > min_heap[root_index].val)
            break;
        mh_node tmp = min_heap[root_index];
        min_heap[root_index] = min_heap[min_index];
        min_heap[min_index] = tmp;
        min_index = root_index;
        root_index = (min_index - 1)/2;
    }
}

void percolate_down_min_heap(mh_node* min_heap, int min_index)
{
    int root = 0;
    while (root < min_index) {
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        if (right < min_index && min_heap[root].val > min_heap[right].val) {
            if (min_heap[left].val < min_heap[right].val) {
                mh_node tmp = min_heap[root];
                min_heap[root] = min_heap[left];
                min_heap[left] = tmp;
                root = left;
            } else {
                mh_node tmp = min_heap[root];
                min_heap[root] = min_heap[right];
                min_heap[right] = tmp;
                root = right;
            }
        } else if (left < min_index && min_heap[root].val > min_heap[left].val) {
            mh_node tmp = min_heap[root];
            min_heap[root] = min_heap[left];
            min_heap[left] = tmp;
            root = left;
        } else {
            break;
        }
    }
}

void print_bucket(mh_node* bucket, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d(%d, %d) ", bucket[i].val, bucket[i].i, bucket[i].j);
    }
    printf("\n");
}

int* mergeKSortedArrays(int arr[][n], int k) 
{
    int *res = calloc(1, sizeof(int) * k * n);
    int res_cnt = 0;
    mh_node *bucket = calloc(1, sizeof(mh_node) * k);
    int cnt_bucket = 0, i = 0, j = 0, num_items = 0;
    while (num_items < n*k) {
        while (cnt_bucket < k && j < n) {
            bucket[cnt_bucket].val = arr[i][j];
            bucket[cnt_bucket].i = i; bucket[cnt_bucket].j = j;
            percolate_up_min_heap(bucket, cnt_bucket);
            cnt_bucket++;
            if (i+1 < k) {
                i++;
            } else {
                j++;
            }
        }
        print_bucket(bucket, cnt_bucket);
        // get the first element from and insert in to result array
        do {
            cnt_bucket--;
            res[num_items++] = bucket[0].val;
            i = bucket[0].i; j = bucket[0].j + 1;
            bucket[0] = bucket[cnt_bucket];
            //bucket[cnt_bucket].val = bucket[cnt_bucket].i = bucket[cnt_bucket].j = -1;
            percolate_down_min_heap(bucket,cnt_bucket);
            print_bucket(bucket, cnt_bucket);
        } while (cnt_bucket > 0 && j >= n);
    }
    return res;
} 
  
int main() 
{ 
   
    int arr[][n] =  {{1, 3, 5, 7}, 
                     {2, 4, 6, 8}, 
                     {0, 9, 10, 11}}; 
    /*int arr[][n] =  {{1, 3, 5}, 
                {2, 4, 6}, 
                {0, 9, 10}};
    int arr[][n] =  {{1}};*/
    int k = sizeof(arr)/sizeof(arr[0]); 
  
    int *output = mergeKSortedArrays(arr, k); 
  
    printf("Merged resultant array is: "); 
    printarr(output, n*k); 
  
    return 0; 
} 


/* Try more Inputs
Case 1:
        int[][] matrix= {{1, 3, 5}, 
                {2, 4, 6}, 
                {0, 9, 10}};  
  
        System.out.println("Merged array is :"); 
        ArrayList<Integer> finalResult = new ArrayList<Integer>();
        for(int val : mergeKSortedArrays(matrix,3))
        {
            finalResult.add(val);
        }
        expected = [0,1,2,3,4,5,6,9,,10]

Case2: 
        int[][] matrix= {1};  
  
        System.out.println("Merged array is :"); 
        ArrayList<Integer> finalResult = new ArrayList<Integer>();
        for(int val : mergeKSortedArrays(matrix,1))
        {
            finalResult.add(val);
        }
        expected = [1]
*/
