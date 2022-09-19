#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Data structure to store a Binary Tree node
typedef struct Node
{
    int data;
    struct Node *left, *right;
}Node;

Node* newNode(int data)
{
    Node* node = calloc(1, sizeof(Node));
    node->data = data;
    return node;
}

// given binary tree rooted at 'root' node
int findDistance(Node *root, Node* x, Node* y)
{
    if (root == NULL)
        return -1;
    if (root->data == x->data || root->data == y->data) {
        return 0;
    }
    int ldepth = findDistance(root->left, x, y) + 1;
    int rdepth = findDistance(root->right, x, y) + 1;
    if (ldepth > 0 && rdepth > 0) {
        printf("\nLCA is %d for x %d y %d and distance is %d\n", root->data, x->data, y->data, ldepth+rdepth);
        return ldepth + rdepth;
    }
    if (ldepth > 0)
        return ldepth;
    if (rdepth > 0)
        return rdepth;    
    return -1;
}

int main()
{
    Node* root = NULL;
    /* Construct below tree
          1
        /   \
       /     \
      2       3
       \     / \
        4   5   6
           / \
          7   8
    */

    root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(5);
	root->right->right = newNode(6);
	root->right->left->left = newNode(7);
	root->right->right->right = newNode(8);

    // find distance between node 7 and node 6
    findDistance(root, root->right->left->left, root->right->right);

    return 0;
}