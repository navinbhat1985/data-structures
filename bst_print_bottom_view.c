#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Data structure to store a Binary Tree node
typedef struct Node
{
	int data;
	struct Node *left, *right;
}Node;

typedef struct node_loc {
    int data;
    int y;
    bool valid;
}node_loc;

void print_bottom_view(Node* root, int x, int y, node_loc *loc, int n)
{
    if (root == NULL)
        return;
    
    int index = (x < 0) ? n+x : x;
    printf("root %d is at x %d, y %d index %d\n", root->data, x, y, index);
    if (loc[index].valid) {
        if (loc[index].y <= y) {
            loc[index].data = root->data;
            loc[index].y = y;
        }
    } else {
        loc[index].data = root->data;
        loc[index].y = y;
        loc[index].valid = true;
    }
    print_bottom_view(root->left, x-1, y+1, loc, n);
    print_bottom_view(root->right, x+1, y+1, loc, n);
}

// Function to print the bottom view of given binary tree
void printBottom(Node *root)
{
    if (root == NULL)
        return;
    node_loc loc[10] = {0};
    print_bottom_view(root, 0, 0, loc, 10);
    printf("\nBottom view of the binary tree is:\n");
    for (int i = 0; i < 10; i++) {
        if (loc[i].valid) {
            printf(" %d ", loc[i].data);
        }
    }
}

Node* newNode(int data)
{
    Node* node = calloc(1, sizeof(Node));
    node->data = data;
    return node;
}

int main()
{
	//Node* root = NULL;

	/*root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(5);
	root->right->right = newNode(6);
	root->right->left->left = newNode(7);
	root->right->left->right = newNode(8);*/
    Node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

	printBottom(root);

	return 0;
}

/* Try more Inputs
Case 1:
result = []
Node root = new Node(20);
root.left = new Node(8);
root.right = new Node(22);
root.left.left = new Node(5);
root.left.right = new Node(3);
root.right.left = new Node(4);
root.right.right = new Node(25);
root.left.right.left = new Node(10);
root.left.right.right = new Node(14);
result = printBottom(root)
expected = [5,10,4,14,25]

Case2: 
Node root = new Node(20);
root.left = new Node(8);
root.right = new Node(22);
root.left.left = new Node(5);
root.left.right = new Node(3);
printBottom(root)
expected = [5,3,22]
*/

