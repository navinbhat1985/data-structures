#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Data structure to store a Binary Tree node
typedef struct Node
{
    int data;
    struct Node *left, *right;
}Node;
 /* Construct below tree
          1
       /     \
      2       3
       \     / \
        4   5   6
           /     \
          7       8
    */
/*
Node* findAncestor(Node* root, Node* node1, int* ancestors, int index)
{
    if (root == NULL)
        return NULL;
    if (root->data == node1->data) 
        return node1;
    ancestors[index] = root->data;
    Node* res = findAncestor(root->left, node1, ancestors, index+1);
    if (NULL == res) {
        res = findAncestor(root->right, node1, ancestors, index+1);
        if (NULL == res)
            ancestors[index] = 0;
    } 
   return res;
}

void findLCA(Node* root, Node* node1, Node* node2)
{
    printf("\nfindLCA for Node1 %d and Node2 %d\n", node1->data, node2->data);
   //Write Your Code here
    int ancestors[10] = {0};
    int n = sizeof(ancestors)/sizeof(ancestors[0]);
    findAncestor(root, node1, ancestors, 0);
    printf("\n Node1 %d ancestors are:", node1->data);
    for (int i = 0; i < 10; i++) {
            printf(" %d ", ancestors[i]);
    }
    findAncestor(root, node2, ancestors, 0);
    printf("\n Node2 %d ancestors are:", node1->data);
    for (int i = 0; i < 10; i++) {
            printf(" %d ", ancestors[i]);
    }
}*/


int findLCA(Node* root, Node* node1, Node* node2)
{
    //printf("\nfindLCA for Node1 %d and Node2 %d\n", node1->data, node2->data);
    if (root == NULL)
        return 0;
    if (root->data == node1->data || root->data == node2->data)
        return root->data;
    int left = findLCA(root->left, node1, node2);
    int right = findLCA(root->right, node1, node2);
    if (left != 0 && right != 0)
        printf("\nLCA of node1 %d and node2 %d is %d\n", node1->data, node2->data, root->data);
    if (left != 0)
        return left;
    if (right != 0)
        return right;
    return 0;
}

/*
int findLCA(Node* root, Node* node1, Node* node2, bool *found1, bool *found2)
{
    //printf("\nfindLCA for Node1 %d and Node2 %d\n", node1->data, node2->data);
    if (root == NULL)
        return;

    if (*found1 == false  && root->data == node1->data) {
        printf("\nFound node1 %d\n", node1->data);
        *found1 = true;
    }
    if (*found2 == false  && root->data == node2->data) {
        printf("\nFound node2 %d\n", node2->data);
        *found2 = true;
    }
   
    if (*found1 == false || *found2 == false) {
        findLCA(root->left, node1, node2, found1, found2);
        findLCA(root->right, node1, node2, found1, found2);
    }
    if (*found1 && *found2){
        printf("\nLCA for %d and %d is %d", node1->data, node2->data, root->data);
    }
    return 0;
}

*/
Node* newNode(int data)
{
    Node* node = calloc(1, sizeof(Node));
    node->data = data;
    return node;
}

int main()
{
    Node* root = NULL;
    /* Construct below tree
          1
        /   \
       /     \
      2       3
       \     / \
        4   5   6
           /     \
          7       8
    */

    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->left = newNode(7);
    root->right->right->right = newNode(8);

    findLCA(root, root->right->left->left, root->right->right);
    findLCA(root, root->right->left->left, newNode(10));
    findLCA(root, root->right->left->left, root->right->left->left);
    findLCA(root, root->right->left->left, root->right->left);
    findLCA(root, root->left, root->right->left);
    findLCA(root, root->left->right, root->right->left);
    findLCA(root, root->right->right->right, root->right->left);
    findLCA(root, root->right->left->left, root->right->left);
    findLCA(root, root->right->left->left, root->right);
    return 0;
}