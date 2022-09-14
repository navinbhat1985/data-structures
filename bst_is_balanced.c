#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
    int   data; 
    struct node* left; 
    struct node* right; 
}node;

int get_height(node* root) 
{
    if (root == NULL)
        return -1;
    int lh = get_height(root->left);
    int rh = get_height(root->right);
    if (lh > rh) {
        return lh+1;
    } else {
        return rh+1;
    }

}

bool isBalanced(node* root, int* height) 
{ 
    if (root == NULL)
        return true;
    int lh = get_height(root->left);
    int rh = get_height(root->right);
    
    int diff = (lh > rh) ? lh-rh : rh-lh;
    if (diff <= 1 && isBalanced(root->left, &lh) && isBalanced(root->right, &rh)) {
        return true;
    }

    return false;
} 

node* newNode(int data) 
{ 
    node* Node = calloc(1, sizeof(node)); 
    Node->data = data; 
    Node->left = NULL; 
    Node->right = NULL; 
    return (Node); 
} 

int main() 
{ 
    int height = 0; 
  
    /* Constructed binary tree is  
            1  
            / \  
            2 3  
            / \ /  
            4 5 6  
            /  
            7  
    */
    node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->left->left->left = newNode(7); 
  
    if (isBalanced(root, &height)) 
        printf( "Tree is balanced, height %d\n", height); 
    else
        printf("Tree is not balanced\n"); 
  
    return 0; 
} 
  
  
/* Try more Inputs
case1:
root = Node(2) 
root.left = Node(3) 
root.right = Node(4) 
root.left.left = Node(5) 
root.left.right = Node(6) 
root.left.left.left = Node(9)
actual = isTreeBalanced(root)
expected = True

case2:
root = Node(2) 
root.left = Node(3) 
root.right = Node(4) 
root.left.left = Node(5) 
root.left.left.left = Node(6) 
root.left.left.left.left = Node(9)
actual = isTreeBalanced(root)
expected = False

*/