#include <stdio.h> 
#include <stdlib.h> 
  

typedef struct node { 
    int data; 
    struct node *left, *right; 
}node; 

void print_left_internal_nodes(node* root)
{
    if (root) {
        if (root->left) {
            printf(" %d ", root->data);
            print_left_internal_nodes(root->left);
        } else if (root->right) {
            printf(" %d ", root->data);
            print_left_internal_nodes(root->right);
        }
    }
}

void print_leaf_nodes(node* root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        printf(" %d ", root->data);
    print_leaf_nodes(root->left);
    print_leaf_nodes(root->right);
}

void print_right_internal_nodes(node* root)
{
    if (root) {
        if (root->right) {
            print_right_internal_nodes(root->right);
            printf(" %d ", root->data);
        } else if (root->left) {
            print_right_internal_nodes(root->left);
            printf(" %d ", root->data);
        }
    }
}
  
// A function to do boundary traversal of a given binary tree 
void printBoundaryNodes(struct node* root) 
{ 
    print_left_internal_nodes(root->left);
    print_leaf_nodes(root);
    print_right_internal_nodes(root->right);
} 
  

struct node* newNode(int data) 
{ 
    struct node* temp = (struct node*)malloc(sizeof(struct node)); 
  
    temp->data = data; 
    temp->left = temp->right = NULL; 
  
    return temp; 
} 
  

int main() 
{ 
   
    struct node* root = newNode(20); 
    root->left = newNode(8); 
    root->left->left = newNode(14); 
    root->left->right = newNode(16); 
    root->left->right->left = newNode(9); 
    root->left->right->right = newNode(17); 
    root->right = newNode(22); 
    root->right->right = newNode(25); 
  
    printBoundaryNodes(root); 
  
    return 0; 
}

/* Try more Inputs
Case1: 
struct node* root = newNode(1);
root->left = newNode(2);
root->right = newNode(3);
root->left->left = newNode(4);
root->left->right = newNode(5);
root->right->left = nnewNode(6);
root->right->right = newNode(7);
root->left->left->left = newNode(8);
root->left->left->right = newNode(9);
root->left->right->right = new Node(10);
root->right->right->left = new Node(11);
root->left->left->right->left = new Node(12);
root->left->left->right->right = new Node(13);
root->right->right->left->left = new Node(14);
printLeftView(root)
expected = [1,2,4,8,12,13,10,6,14,11,7,3]
*/