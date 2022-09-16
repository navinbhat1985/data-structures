#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
	node->left = node->right = NULL;

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
bool isBST(Node* root)
{
    if (root == NULL)
        return true;

    if (root->left && (root->left->data > root->data)) {
        printf("\n Invalid root->left->data %d  is > root->data %d\n", root->left->data, root->data);
        return false;
    }

    if (root->right && (root->right->data < root->data)) {
        printf("\n Invalid root->right->data %d  is < root->data %d\n", root->right->data, root->data);
        return false;
    }
    
    bool valid = isBST(root->left);
    if (valid) {
        valid = isBST(root->right);
    }

    return valid;
}

int main()
{
	/*Node* root = NULL;
	int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
    int sz = sizeof(keys)/sizeof(keys[0]);
	for (int i = 0; i < sz; i++)
		root = insert(root, keys[i]);*/
    
    struct Node* root = newNode(20); 
    root->left = newNode(8); 
    root->left->left = newNode(14); 
    root->left->right = newNode(16); 
    root->left->right->left = newNode(9); 
    root->left->right->right = newNode(17); 
    root->right = newNode(22); 
    root->right->right = newNode(25);

	// swap nodes
	printf("Is valid BST is %d\n", isBST(root));

	return 0;
}