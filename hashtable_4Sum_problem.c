#include <iostream>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

 
typedef pair<int, int> Pair;

map<int, vector<Pair>> hash_map;

// Function to check if four sum exists in an array with the given sum
bool fourSum(int arr[], int n, int sum)
{
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            int val = sum - (arr[i] + arr[j]);
            map<int, vector<Pair>>::iterator it = hash_map.find(val) ;
            if (it != hash_map.end()) {
                vector<pair<int,int>> vec = it->second;
                for (int x = 0; x < vec.size(); x++) {
                    int k = vec[x].first;
                    int l = vec[x].second;
                    if (i != k && i != l && j != k && j != l) {
                        printf("i %d j %d k %d l %d are the 4 unique indices with sum %d\n", i, j, k, l, sum);
                        return true;
                    }
                }
            }
            //hash_map.emplace((arr[i]+arr[j]), new vector<pair<int, int>>()) ;
            vector<pair<int,int>> vec ;// = hash_map[(arr[i]+arr[j])];
            vec.push_back(make_pair(i,j));
            hash_map.emplace((arr[i]+arr[j]), vec) ;
        }
    }
    return false;
}
 
int main()
{
    int arr[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
    int sum = 20;
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    if (!fourSum(arr, n, sum)) {
        cout << "fourSum Doesn't Exist";
    }
 
    return 0;
}

