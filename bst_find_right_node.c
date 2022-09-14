#include <stdio.h>
#include <stdlib.h>

// Data structure to store a Binary Tree node
typedef struct Node
{
    int data;
    struct Node *left, *right;
}Node;

Node* create_node(int data)
{
    Node* node = calloc(1, sizeof(Node));
    node->data = data;
    return node;
}

Node* get_next_right(Node* root_next)
{
    if (root_next == NULL) {
        return NULL;
    }
    Node* right = NULL;
    if (root_next->left)
        right = root_next->left;
    else if (root_next->right)
        right = root_next->right;
    else
        right = NULL;

    printf("right of root_next %d is %d\n", root_next->data, (right)? right->data: 0);
    return right;
}
 /* Construct below Tree
              1
            /  \
           /    \
          2      3
         / \      \
        4   5      6
                  / \
                 7   8
    */
Node* find_right_node(Node* root, Node* root_right, int data)
{
    Node* right = NULL;
    if (root == NULL)
        return NULL;

    printf("root %d root_right %d data %d\n", root->data, root_right ? root_right->data : 0, data);
    if (root->data == data) {
        right = root_right;
        return right;
    }
    
    if (root->left && root->left->data == data) {
        printf("Found root->left %d data %d\n", root->left->data, data);
        if (root->right) {
            right = root->right;
        } else {
            right = get_next_right(root_right);
        }
    } else if (root->right && root->right->data == data) {
        printf("Found root->right %d data %d\n", root->right->data, data);
        right = get_next_right(root_right);
    } else {
        if (right == NULL && root->left) {
            printf("Find inside root->left %d data %d\n", root->left->data, data);
            Node* next_right = NULL;
            if (root->right) {
                next_right = root->right;
            } else {
                next_right = get_next_right(root_right);
            }
            right = find_right_node(root->left, next_right, data);
        } 
        if (right == NULL && root->right) {
            printf("Find inside root->right %d data %d\n", root->right->data, data);
            Node* next_right = get_next_right(root_right);
            right = find_right_node(root->right, next_right, data);
        }
    }
    
    return right;
}

// Function to find next node of given node in the same level
// in given binary tree
Node* findRightNode(Node* root, int val)
{
   if (root == NULL)
       return NULL;
   printf("Inside findRightNode\n");
   return find_right_node(root, NULL, val);
}

int main()
{
    Node* root = NULL;

    /* Construct below Tree
              1
            /  \
           /    \
          2      3
         / \      \
        4   5      6
                  / \
                 7   8
    */
    /*root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	root->right->left = create_node(6);
	root->right->left->left = create_node(7);
	root->right->left->right = create_node(8);*/
    
    root = create_node(1)
    root.left = create_node(2)
    root.right = create_node(3)
    root.left.left = create_node(4)
    root.left.right = create_node(5)
    root.right.left = create_node(6)
    root.right.left.left = create_node(7)
    root.right.left.right = create_node(8)

    printf("main root->data %d\n", root->data);
    Node *right = findRightNode(root, 6);
    if (right)
        printf("Right Node is %d\n", right->data);
    else
        printf ("Right Node doesn't exists\n");

    return 0;
}
/* Try more Inputs
case1:
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.left.left = Node(7)
root.right.left.right = Node(8)
actual = findRightNode(root, 5)
expected = 6

case2:
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.left.left = Node(7)
root.right.left.right = Node(8)
actual = findRightNode(root, 2)
expected = 3

case3:
root = Node(1)
root.left = Node(2)
root.right = Node(3)
actual = findRightNode(root, 2)
expected = 3

*/


