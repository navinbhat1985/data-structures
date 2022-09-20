#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
	int data;
	struct Node *left, *right;
}Node;

Node* newNode(int data)
{
    Node* node = calloc(1, sizeof(Node));
    node->data = data;
    return node;
}

#define MAX_HEIGHT 10

typedef struct list {
    Node* node;
    struct list* next;
}list;

list* node_list[MAX_HEIGHT] = {0};
int max_height = 0;
// Function to print reverse level order traversal of given binary tree
int reverseLevelOrder(Node* root, int height)
{
    if (root == NULL)
        return 0;
    list* l = calloc(1, sizeof(list));
    l->node = root;
    l->next = node_list[height];
    node_list[height] = l;
    if (height > max_height)
        max_height = height;
    reverseLevelOrder(root->left, height+1);
    reverseLevelOrder(root->right, height+1);
    return max_height;
}

int main()
{
	Node* root = NULL;

	root = newNode(15);
	root->left = newNode(10);
	root->right = newNode(20);
	root->left->left = newNode(8);
	root->left->right = newNode(12);
	root->right->left = newNode(16);
	root->right->right = newNode(25);

	int max_height = reverseLevelOrder(root, 0);
    printf("max height is %d\n", max_height);
    
    for (int i = max_height; i >= 0; i--) {
        list *cur = node_list[i];
        printf("\nNodes at level %d: ", i);
        while (cur) {
            printf(" %d ", (cur->node) ? cur->node->data : -1);
            cur = cur->next;
        }
    }

	return 0;
}

/* Try more Inputs
case1:
Node tree = new Node(); 
tree->root = new Node(1); 
tree->root->left = new Node(2); 
tree->root->right = new Node(3); 
actual = reverseLevelOrder(tree)
expect = 2 3 1

case2: 
Node tree = new Node(); 
tree->root = new Node(1); 
tree->root->left = new Node(2); 
tree->root->right = new Node(3); 
tree->root->right->left = new Node(-4); 
tree->root->right->right = new Node(-5); 
expect = -4 -5 2 3 1
*/