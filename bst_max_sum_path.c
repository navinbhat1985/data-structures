#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* A tree node structure */
typedef struct node { 
    int data; 
    struct node* left;
    struct node* right; 
}node; 
 
/*
// A utility function that prints all nodes 
// on the path from root to target_leaf 
bool printPath(node* root, 
               node* target_leaf) 
{ 
    // base case 
    if (root == NULL) 
        return false; 
  
    // return true if this node is the target_leaf 
    // or target leaf is present in one of its 
    // descendants 
    if (root == target_leaf || printPath(root->left, target_leaf) ||  
                               printPath(root->right, target_leaf)) { 
        cout << root->data << " "; 
        return true; 
    } 
  
    return false; 
} 
*/
bool print_path(node* root, node* target)
{
    if (root == NULL)
        return false;
    if (root == target || print_path(root->left, target) || print_path(root->right, target)) {
        printf(" %d " , root->data);
        return true;
    }
    return false;
}

int max_sum = 0;  
// Returns the maximum sum and prints the nodes on max 
// sum path 
int maxSumPath(node* root, int sum) 
{
    if (root == NULL)
        return sum;
    sum += root->data;
    if (sum > max_sum)
        max_sum = sum;
    maxSumPath(root->left, sum);
    maxSumPath(root->right, sum);
    return sum;
} 
  
/* Utility function to create a new Binary Tree node */
node* newNode(int data) 
{ 
    node* temp = calloc(1, sizeof(node)); 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
} 
  

int main() 
{ 
    node* root = NULL; 
  
    /* Constructing tree given in the above figure */
    root = newNode(10); 
    root->left = newNode(-2); 
    root->right = newNode(7); 
    root->left->left = newNode(8); 
    root->left->right = newNode(-4); 
  
    maxSumPath(root, 0); 
    print_path(root, root->right);
    printf("\nSum of the nodes is %d\n", max_sum); 
    return 0; 
} 