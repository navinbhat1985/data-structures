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

#define MAX(a,b) ((a>b) ? a : b)

int max_diameter = 0;
int findDiameter(Node* root)
{
    if (root == NULL)
        return 0;
    int lheight = findDiameter(root->left);
    int rheight = findDiameter(root->right);
    int diameter = lheight + rheight + 1;
    if (diameter > max_diameter)
        max_diameter = diameter;
    return (1 + MAX(lheight,rheight));
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

    findDiameter(root);
	printf("\nDiameter of the BT is %d\n", max_diameter);

	return 0;
}


/* Try more Inputs
Case 1:
BinaryTree tree = new BinaryTree();
tree.root = new Node(12);
tree.root.left = new Node(10);
tree.root.right = new Node(30);
tree.root.right.left = new Node(25);
tree.root.right.right = new Node(40);
printLeftView(root)
expected = [12,10,25]

Case2: 
BinaryTree root = newNode(10);
root.left = newNode(12);
root.right = newNode(3);
root.left.right = newNode(4);
root.right.left = newNode(5);
root.right.left.right = newNode(6);
root.right.left.right.left = newNode(18);
root.right.left.right.right = newNode(7);
printLeftView(root)
expected = [10,12,4,6,18]
*/