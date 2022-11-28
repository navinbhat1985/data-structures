#include <bits/stdc++.h> 
#include <stack>
using namespace std; 
  

bool areParanthesisBalanced(string expr) 
{
    if ((expr.length() % 2) != 0) {
        return false;
    }
    stack<char> stk;
    for (unsigned int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (ch == '{') {
            stk.push('}');
        } else if (ch == '(') {
            stk.push(')');
        } else if (ch == '[') {
            stk.push(']');
        } else {
            if (stk.empty() || stk.top() != ch) {
                return false;
            }
            stk.pop();
        }
        
    }
    return stk.empty();
} 
  

int main() 
{ 
    string expr = "{()}[]{}{}{}"; 
  
    if (areParanthesisBalanced(expr)) 
        cout << "Balanced"; 
    else
        cout << "Not Balanced"; 
    return 0; 
}