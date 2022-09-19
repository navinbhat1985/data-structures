#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Data structure to store a Binary Search Tree node
typedef struct Node
{
	int data;
	struct Node *left, *right;
}Node;

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = calloc(1, sizeof(Node));
	node->data = key;
	return node;
}

// Recursive function to insert a key into BST
Node* insert(Node* root, int key)
{
	// if the root is null, create a new node and return it
	if (root == NULL)
		return newNode(key);

	// if given key is less than the root node, recur for left subtree
	if (key < root->data)
		root->left = insert(root->left, key);
	// if given key is more than the root node, recur for right subtree
	else
		root->right = insert(root->right, key);

	return root;
}


// Function to determine if given Binary Tree is a BST or not
bool isBST(Node* root, int min, int max)
{
    if (root == NULL)
        return true;
    printf("root %d min %d max %d\n", root->data, min, max);
    if (root->data < min || root->data > max) {
        return false;
    }
    bool valid = isBST(root->left, min, root->data-1);
    if (valid) {
        valid = isBST(root->right, root->data+1, max);
    }
    return valid;
}

int main()
{
/*	Node* root = NULL;
	int keys[] = { 15, 10, 20, 8, 12, 16, 25 };

    int n = sizeof(keys)/sizeof(keys[0]);
	for (int i = 0; i < n; i++)
		root = insert(root, keys[i]);
    */
    Node* root = NULL;

	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(5);
	root->right->right = newNode(6);
	root->right->left->left = newNode(7);
	root->right->left->right = newNode(8);

	// swap nodes
	printf("\n isBST = %d\n", isBST(root, INT_MIN, INT_MAX));

	return 0;
}
