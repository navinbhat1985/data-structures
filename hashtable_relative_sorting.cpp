#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <map>
using namespace std;
 
void relativeSort(int arr1[], int arr2[], int m, int n)
{
    map<int,int> freq;
    for (int i = 0; i < m; i++) {
        auto it = freq.find(arr1[i]);
        if (it != freq.end()) {
            it->second++;
        } else {
            freq[arr1[i]] = 1;
        }
    }
    cout << "frequency of all items in arr1" << endl;
    for (auto it = freq.begin(); it != freq.end() ; it++) {
        cout << it->first << " -> " << it->second << endl;
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        int val = arr2[i];
        if (freq.find(val) != freq.end()) {
            int count = freq[val];
            while (count) {
                arr1[index++] = val;
                count--;
            }
            freq.erase(val);
        }
    }
    cout << "frequency of remaining the items in arr1" << endl;
    for (auto it = freq.begin(); it != freq.end() ; it++) {
        cout << it->first << " -> " << it->second << endl;
        int val = it->first;
        int count = it->second;
        while (count) {
            arr1[index++] = val;
            count--;
        }
        freq.erase(val);
    }
    
}
 
int main()
{
    int arr1[] = { 5, 8, 9, 3, 5, 7, 1, 3, 4, 9, 3, 5, 1, 8, 4 };
    int arr2[] = { 3, 5, 7, 2 };
 
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
 
    relativeSort(arr1, arr2, m, n);
 
    cout << "After sorting the array is : ";
    for (int i = 0; i < m; i++)
        cout << arr1[i] << " ";
    cout << endl;
 
    return 0;
}

/* Try more Inputs
Case 1:
int[] arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
int[] arr2 = { 2,1,4,3,9,6 };
int m = sizeof(arr1) / sizeof(arr1[0]);
int n = sizeof(arr2) / sizeof(arr2[0]);
customSort(arr1, arr2);
expected = [2,2,2,1,4,3,3,9,6,7,19]

Case 1:
int[] arr1 = { 2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8 };
int[] arr2 = {2, 1, 8, 3};
int m = sizeof(arr1) / sizeof(arr1[0]);
int n = sizeof(arr2) / sizeof(arr2[0]);
customSort(arr1, arr2);
expected = [2,2,1,1,8,8,3,5,6,7,9]
*/
