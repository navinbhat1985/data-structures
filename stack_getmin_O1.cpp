#include <bits/stdc++.h> 
#include <stack> 
using namespace std; 
  
struct MyStack 
{ 
    stack<int> stk; 
    int minValue; 
  
    void getMin() 
    { 
        if (stk.empty()) 
            cout << "Stack is empty\n"; 
        else
            cout <<"Minimum Element in the stack is: "
                 << minValue << "\n"; 
    } 
    
    void peek() 
    { 
        if (stk.empty()) 
        { 
            cout << "Stack is empty "; 
            return; 
        } 
  
        int t = stk.top(); // Top element. 
  
        cout << "Top Most Element is: "; 
  
        // If t < minValue means minValue stores 
        // value of t. 
        (t < minValue)? cout << minValue: cout << t; 
    } 
  
    /* if tos is < minValue, then  minVal = 2*minVal - tos */
    // Remove the top element from Stack 
    void pop() 
    { 
        if (stk.empty()) 
        { 
            cout << "Stack is empty\n"; 
            return; 
        } 
  
        cout << "Top Most Element Removed: "; 
        int t = stk.top(); 
        stk.pop(); 
  
        // Minimum will change as the minimum element 
        // of the stack is being removed. 
        if (t < minValue) 
        { 
            cout << minValue << "\n"; 
            minValue = 2*minValue - t; 
        } 
  
        else
            cout << t << "\n"; 
    } 
  
    // Removes top element from MyStack 
    /* If x < minVal, then tos = 2*x - minVal , minVal = x */
    void push(int x) 
    { 
        // Insert new number into the stack 
        if (stk.empty()) 
        { 
            minValue = x; 
            stk.push(x); 
            cout <<  "Number Inserted: " << x << "\n"; 
            return; 
        } 
  
        // If new number is less than minValue 
        if (x < minValue) 
        { 
            stk.push(2*x - minValue); 
            minValue = x; 
        } 
  
        else
           stk.push(x); 
  
        cout <<  "Number Inserted: " << x << "\n"; 
    } 
}; 

int main() 
{ 
    MyStack stk; 
    stk.push(3); 
    stk.push(5); 
    stk.getMin(); 
    stk.push(2); 
    stk.push(1); 
    stk.getMin(); 
    stk.pop(); 
    stk.getMin(); 
    stk.pop(); 
    stk.peek(); 
  
    return 0; 
} 


/* Try more Inputs
Case 1:
MyStack stack; 
stack.push(13); 
stack.push(5);
int result = s.getMin();
expected = 5
Case 2: 
MyStack stack; 
stack.push(-1); 
stack.push(2);
int result = s.getMin();
expected = -1
*/