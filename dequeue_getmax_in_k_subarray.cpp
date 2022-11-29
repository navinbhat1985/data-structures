#include <bits/stdc++.h>
using namespace std;
 
void printKMax(int arr[], int n, int k)
{
     
    // Create a Double Ended Queue, 
    // queue that will store indexes 
    // of array elements
    // The queue will store indexes 
    // of useful elements in every 
    // window and it will
    // maintain decreasing order of 
    // values from front to rear in queue, i.e.,
    // arr[queue.front[]] to arr[queue.rear()] 
    // are sorted in decreasing order
    std::deque<int> queue(k);
 
    /* Process first k (or first window) 
     elements of array */
    int i;
    for (i = 0; i < k; ++i) 
    {
     
        // For every element, the previous
        // smaller elements are useless so
        // remove them from queue
        while ((!queue.empty()) && arr[i] >= 
                            arr[queue.back()])
           
             // Remove from rear
            queue.pop_back();
 
        // Add new element at rear of queue
        queue.push_back(i);
    }
 
    // Process rest of the elements, 
    // i.e., from arr[k] to arr[n-1]
    for (; i < n; ++i) 
    {
     
        // The element at the front of 
        // the queue is the largest element of
        // previous window, so print it
        cout << arr[queue.front()] << " ";
 
        // Remove the elements which 
        // are out of this window
        while ((!queue.empty()) && queue.front() <= 
                                           i - k)
           
            // Remove from front of queue
            queue.pop_front(); 
 
        // Remove all elements 
        // smaller than the currently
        // being added element (remove 
        // useless elements)
        while ((!queue.empty()) && arr[i] >= 
                             arr[queue.back()])
            queue.pop_back();
 
        // Add current element at the rear of queue
        queue.push_back(i);
    }
 
    // Print the maximum element 
    // of last window
    cout << arr[queue.front()];
}
 
int main()
{
    int arr[] = { 8, 6, 10, 7, 5, 17, 14, 87, 15 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}


/* Try more Inputs
Case 1:
int array[] = { 1, 2, 3, 1, 4, 5, 2, 3, 6 }; 
int k = 3; 
printKMax(array, array.length, k)
expected = 3 3 4 5 5 5 6
Case2:
int array[] = { 8, 5, 10, 7, 9, 4, 15, 12, 90, 13 }; 
int k = 4; 
printKMax(array, array.length, k)
expected = 10 10 10 15 15 90 90

*/