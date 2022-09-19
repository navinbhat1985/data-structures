#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Data structure to store a Binary Tree node
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

// Function to print the inorder traversal of a binary tree
void inorder_print(Node* root)
{
	if (root == NULL)
		return;

	inorder_print(root->left);
	printf(" %d ", root->data );
	inorder_print(root->right);
}

int find_index(int* inorder, int start, int end, int key)
{
    printf("\nSearch for %d in inorder start %d end %d\n", key, start, end);
    for (int i = start; i <= end; i++) {
        if (inorder[i] == key) {
            printf("\n%d found at index %d\n", key, i);
            return i;
        }
    }
    return -1;
}

// Recursive function to build a binary search tree from
// its postorder sequence
Node* buildTree(int *postorder, int *inorder, int start, int end, int* current)
{
    printf("start %d end %d current %d\n", start, end, *current);
    if (start > end)
        return NULL;
    *current = (*current) - 1;
    Node* node = newNode(postorder[*current]);
    if (start == end)
        return node;
    int index = find_index(inorder, start, end, postorder[*current]);
    node->right = buildTree(postorder, inorder, index+1, end, current);
    node->left = buildTree(postorder, inorder, start, index-1, current);
    return node;
}

int main()
{
	/* Construct below BST
			  15
			/	\
		   /	  \
		  10	   20
		 /  \	 /  \
		/	\   /	\
	   8	 12 16	25
	*/

	// postorder traversal of BST
	int postorder[] = { 8, 12, 10, 16, 25, 20, 15 };
    int inorder[]   = { 8, 10, 12, 15, 16, 20, 25 };

    int n = sizeof(postorder)/sizeof(postorder[0]);
    int cur = n;
	// construct the BST
	Node* root = buildTree(postorder, inorder, 0, n-1, &cur);

	// print the BST
	printf("\nInorder Traversal of BST is : ");

	// inorder on the BST always returns a sorted sequence
	inorder_print(root);

	return 0;
}


/* Try more Inputs
Case 1:
int[] inorder = { 4, 2, 1, 7, 5, 8, 3, 6 };
int[] postorder = { 4, 2, 7, 8, 5, 6, 3, 1};
int result = [];
Node root = construct(inorder, postorder);
inorderTraversal(root,result);
expected = [4, 2, 1, 7, 5, 8, 3, 6]

Case2: 
int[] inorder = { 9,3,15,20,7 };
int[] postorder = { 9,15,7,20,3};
int result = [];
Node root = construct(inorder, postorder);
inorderTraversal(root,result);
expected = [9,3,15,20,7]
*/
