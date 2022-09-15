#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


// Data structure to store a Binary Search Tree node
typedef struct Node {
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

// Function to perform inorder traversal of the BST
void inorder(Node *root)
{
	if (root == NULL)
		return;

	inorder(root->left);
	printf(" %d ", root->data);
	inorder(root->right);
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

// Function to find a node in a BST
void findNode(Node* root, int key)
{
    if (root == NULL)
        return;
    if (root->data == key) {
        printf("\nFound %d in tree\n", root->data);
        return;
    }
    findNode(root->left, key);
    findNode(root->right, key);
}

void move_to_leaf(Node* node, Node* parent)
{
    if (node == NULL)
        return;
    
    Node* left = node->left;
    Node* right = node->right;
    if (parent) {
        if (parent->left == node) {
            parent->left = (left) ? left : right;
        } else {
            parent->right = (left) ? left : right;
        }
    }
    if (node->left) {
        node->left = left->left;
        node->right = left->right;
        left->left = node;
        left->right = right;
        parent = left;
    } else if (node->right) {
        node->left = right->left;
        node->right = right->right;
        right->left = left;
        right->right = node;
        parent = right;
    } else {
        printf("\n%d is a leaf node\n", node->data);
        return;
    }
    
    return move_to_leaf(node, parent);
}

// Function to delete node from a BST
bool deleteNode(Node* root, Node* parent, int key)
{
    if (root == NULL)
        return false;
    
    if (root->data == key) {
        printf("\nFound %d in tree at root move it to leaf\n", key);
        move_to_leaf(root, parent);
        free(root);
        return true;
    } 
    printf("\nSearch %d in root %d left\n", key, root->data);
    bool ret = deleteNode(root->left, root, key);
    if (false == ret) {
        printf("\nSearch %d in root %d right\n", key, root->data);
        ret = deleteNode(root->right, root, key);
    }
    return ret;
}

int main()
{
	Node* root = NULL;
	int keys[] = { 15, 10, 20, 8, 12, 16 };
    

    int n = sizeof(keys)/sizeof(keys[0]);
    for (int i = 0; i < n; i++) {
		root = insert(root, keys[i]);
    }
    printf("\nBST nodes before delete:");
    inorder(root);
	//findNode(root, 16);
    deleteNode(root, NULL, 10);
    printf("\nBST nodes after delete :");
	inorder(root);

	return 0;
}