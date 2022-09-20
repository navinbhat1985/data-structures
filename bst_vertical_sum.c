#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node {
	int data;
	struct Node *left, *right;
} Node;

Node* newNode(int data)
{
    Node* n = calloc(1, sizeof(Node));
    n->data = data;
    return n;
}

int vert_sum[50] = {0};
int vsz = sizeof(vert_sum)/sizeof(vert_sum[0]);

// Function to find and print the vertical sum of given binary tree
void verticalSum(Node* root, int x)
{
    if (root == NULL)
        return;
    vert_sum[x] += root->data;
    verticalSum(root->left, x-1);
    verticalSum(root->right, x+1);
}

int main()
{
	/* Construct below tree
		  1
		/   \
	   /	 \
	  2	   3
			/   \
		   /	 \
		  5	   6
		/   \
	   /	 \
	  7	   8
	*/

	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(5);
	root->right->right = newNode(6);
	root->right->left->left = newNode(7);
	root->right->left->right = newNode(8);

	verticalSum(root, vsz/2);
    for (int i = 0; i < vsz; i++) {
        if (vert_sum[i])
            printf(" %d ", vert_sum[i]);
    }

	return 0;
}

/* Try more Inputs
TreeNode root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(3);
root.left.left = new TreeNode(4);
root.left.right = new TreeNode(5);
root.right.left = new TreeNode(6);
root.right.right = new TreeNode(7);
verticalSum(root)
expected = [4, 2, 12, 3, 7]
*/