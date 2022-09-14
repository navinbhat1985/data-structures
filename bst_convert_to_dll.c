#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node* create_node(int data)
{
    Node* node = calloc(1, sizeof(Node));
    node->data = data;
    return node;
}

Node* dll_head = NULL;
// in-place convert given Binary Tree to a Doubly Linked List
Node* convert(Node* root, Node* parent)
{
    if (root == NULL)
        return parent;
    parent = convert(root->left, parent);
    printf("root %d parent %d\n", root->data, (parent) ? parent->data : -1);
    if (parent == NULL) {
        parent = root;
        dll_head = root;
    } else {
        root->left = parent;
        parent->right = root;
        parent = root;
    }
    parent = convert(root->right, parent);
    return parent;
}

void print_dll(Node* root)
{
    if (root == NULL)
        return;
    while (root) {
        printf(" %d -> ", root->data);
        root = root->right;
    }
}

int main()
{
    /* Construct below tree
              1
           /     \
          2       3
         / \     / \
        4   5   6   7
    */

    Node* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    root->right->left = create_node(6);
    root->right->right = create_node(7);
 
    convert(root, NULL);
    print_dll(dll_head);
 
    return 0;
}

/* Try more Inputs
Case 1:
BinaryTree tree = new BinaryTree();
BinaryTree tree = new BinaryTree();
tree.root = new Node(10);
tree.root.left = new Node(12);
tree.root.right = new Node(15);
tree.root.left.left = new Node(25);
tree.root.left.right = new Node(30);
tree.root.right.left = new Node(36);
display(root)
expected = [25 ,12 ,30 ,10 ,36 ,15]

Case 1:
BinaryTree tree = new BinaryTree();
BinaryTree tree = new BinaryTree();
tree.root = new Node(10);
tree.root.left = new Node(12);
display(root)
expected = [12,10]

*/


