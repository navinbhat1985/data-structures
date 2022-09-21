#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node 
{ 
    int data; 
    struct Node* left, *right; 
}Node; 
   
struct Node* newNode(int data) 
{ 
    struct Node* newNode = calloc(1, sizeof(Node)); 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return (newNode); 
} 
  
/*int findMaxPathSum(Node* root, int &result) 
{ 
     //Practise Yourself : Write your code Here
     return 0;
} */

#define MAX(a,b) ((a > b) ? a : b)
int result = 0;
int findMaxSum(Node *root) 
{ 
    if (root == NULL)
        return 0;
    int left = findMaxSum(root->left);
    int right = findMaxSum(root->right);
    int data = root->data;
    int max_value  = MAX(data, MAX(data+left, data+right));
    int max_top = MAX(max_value, left+right+data);
    result = MAX(result, max_top);
    return max_value; 
} 
  

int main(void) 
{ 
    struct Node *root = newNode(10); 
    root->left        = newNode(2); 
    root->right       = newNode(15); 
    root->left->left  = newNode(-4); 
    root->left->right = newNode(-6); 
    root->left->left->left  = newNode(28); 
    root->left->left->right  = newNode(-22); 
    root->right->right = newNode(-25); 
    root->right->right->left   = newNode(3); 
    root->right->right->right  = newNode(4); 
    printf( "Max path sum  %d\n", findMaxSum(root)); 
    return 0; 
} 



/* Try more Inputs
case1:
root = None
root = newNode(1)  
root.left = newNode(2)  
root.right = newNode(3)  
resultRoot = maxPathUtility(root)
expected = 6

case2:
Node root = new Node(1);
root.left = new Node(2);
root.right = new Node(10);
root.left.left = new Node(-1);
root.left.right = new Node(-4);
root.right.left = new Node(-5);
root.right.right = new Node(-6);
root.left.right.left = new Node(4);
root.right.left.left = new Node(7);
root.right.left.right = new Node(4);
root.right.left.left.right = new Node(-2);
actual = maxPathUtility(root)
expected = 19
*/
