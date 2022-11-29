#include<iostream> 
#include<stack> 
using namespace std; 
  
void nextGreaterElement(int arr[], int n) 
{
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && arr[i] > stk.top()) {
            cout << "Next greater element on right of " << stk.top() << " is " << arr[i] << endl;
            stk.pop();
        }
        stk.push(arr[i]);
    }
    while(!stk.empty()) {
        cout << "Next greater element on right of " << stk.top() << " is NULL" << endl;
        stk.pop();
    }
} 
  
int main() 
{ 
    int arr[] = {11,13,21,3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    nextGreaterElement(arr, n); 
    return 0; 
} 