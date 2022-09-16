#include<stdio.h>  
#include<stdlib.h>
#include<stdbool.h>

typedef struct node 
{ 
    int data; 
    struct node *left, *right; 
}node; 

void print_nodes_down_at_k(node* root, int k)
{
    if (root == NULL || k < 0)
        return;
    if (k == 0)
        printf(" %d ", root->data);
    print_nodes_down_at_k(root->left, k-1);
    print_nodes_down_at_k(root->right, k-1);
}
  
// Prints all nodes at distance k from a given target node. 
// The k distant nodes may be upward or downward.  This function 
// Returns distance of root from target node, it returns -1 if target 
// node is not present in tree rooted with root. 
int printkdistanceNode(node* root, node* target , int k) 
{
    if (root == NULL)
        return -1;
    if(root->data == target->data) {
        printf("\nNodes below target: \n");
        print_nodes_down_at_k(target, k);
        return 1;
    }
    int dleft = printkdistanceNode(root->left, target,k);
    if (dleft != -1) {
        if (dleft == k) {
            printf(" %d ", root->data);
        } else {
            print_nodes_down_at_k(root->right, k-dleft-1);
        }
        return dleft+1;
    }
    int dright = printkdistanceNode(root->right, target,k);
    if (dright != -1) {
        if (dright == k) {
            printf(" %d ", root->data);
        } else {
            print_nodes_down_at_k(root->left, k-dright-1);
        }
        return dright+1;
    }
    return -1;
} 
   
node *newnode(int data) 
{ 
    node *temp = calloc(1, sizeof(node)); 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
int main() 
{ 
    
    node * root = newnode(22); 
    root->left = newnode(18); 
    root->right = newnode(23); 
    root->left->left = newnode(14); 
    root->left->right = newnode(11); 
    root->left->right->left = newnode(9); 
    root->left->right->right = newnode(10); 
    node * target = root->left->right; 
    printkdistanceNode(root, target, 1);
    //print_nodes_down_at_k(target,2);
    return 0; 
}
