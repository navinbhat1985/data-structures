#include  <stdio.h>
#include  <stdlib.h>

// Data structure to store a Binary Tree node
typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* next;
}Node;
 
// Function to print a given linked list
void printList(Node* head)
{
    while (head) {
        printf ("%d -> ", head->data);
        head = head->next;
    }
    printf("null\n");
}

Node* create_node(int data)
{
    Node* node = calloc(1, sizeof(Node));
    node->data = data;
    return node;
}

// Recursive function to find the first node in next level of the root node
Node* findNextNode(Node* root)
{
    Node* next = NULL;
    if (root == NULL)
        return NULL;
    if (root->next) {
        if (root->next->left) {
            next = root->next->left;
        } else if (root->next->right) {
            next = root->next->right;
        } else {
            findNextNode(root->next->next);
        }
    }
    return next;
}

Node* get_next_available(Node* root)
{
    if (root == NULL)
        return NULL;
    printf("get_next_available for %d\n", root->data);
    Node* next = NULL;
    if (root->left) {
        next = root->left;
    } else if (root->right) {
        next = root->right;
    } else {
        next = get_next_available(root->next);
    }
    
    return next;
}

// Recursive function to link nodes present in each level of a binary tree
// in the form of a linked list
void linkNodes(Node* root)
{
    if (root == NULL)
        return;
    if (root->left && root->right) {
        root->left->next = root->right;
        root->right->next = get_next_available(root->next); //(root->next->left) ? root->next->left : root->next->right;
    } else if (root->next && (root->left || root->right)) {
        if (root->right) {
            root->right->next = get_next_available(root->next); //(root->next->left) ? root->next->left : root->next->right;
        } else if (root->left) {
            root->left->next = get_next_available(root->next); //(root->next->left) ? root->next->left : root->next->right;
        }
    }
    linkNodes(root->right);
    linkNodes(root->left);
}
 
int main()
{
    /* Construct below Tree
           1
         /   \
        2     3
       / \     \
      4   5     6
       \       /
        7     8
    */
 
    Node* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    root->right->right = create_node(6);
    root->left->left->right = create_node(7);
    root->right->right->left = create_node(8);
 
    // link nodes at the same level
    printf("linkNodes root %d %d\n", root->data, root->right->right->left->data);
    linkNodes(root);
 
    // print the nodes
    Node* node = root;
    while (node) {
        // print current level
        printList(node);
        // find leftmost node of the next level
        if (node->left)
            node = node->left;
        else if (node->right)
            node = node->right;
        else
           node = findNextNode(node);
    }
 
    return 0;
}
