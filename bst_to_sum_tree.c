#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
// Function to print pre-order traversal of given tree
void preorder(Node* root)
{
	if (root == NULL)
		 return;

	printf(" %d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

// Recursive function to in-place convert the given binary tree to its
// sum tree by traversing the tree in postorder manner
int convertToSumTree(Node *root)
{
    if (root == NULL)
        return 0;
    
    int left = convertToSumTree(root->left);
    int right = convertToSumTree(root->right);
    int old_val = root->data;
    int new_val = left + right;
    root->data = new_val;
    return old_val+new_val;
}

int main()
{
	Node* root = NULL;

	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(5);
	root->right->right = newNode(6);
	root->right->left->left = newNode(7);
	root->right->left->right = newNode(8);

	convertToSumTree(root);
	preorder(root);

	return 0;
}