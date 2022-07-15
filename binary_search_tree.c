#include  <stdio.h>
#include  <stdlib.h>
#include  <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* bst_insert(Node* root, int data)
{
    if (NULL == root) {
        root = calloc(1, sizeof(Node));
        root->data = data;
        return root;
    }
    
    if (data < root->data) {
        root->left = bst_insert(root->left, data);
    } else if (data >= root->data) {
        root->right = bst_insert(root->right, data);
    }
    return root;
}

Node* bst_search(Node *root, int data)
{
    if (root == NULL) {
        printf("data %d is not found in the bst\n", data);
        return root;
    } else if (root->data == data) {
        printf("found %d in the bst\n", data);
        return root;
    }
    
    if (data < root->data) {
        return (bst_search(root->left, data));
    }
    return (bst_search(root->right, data));
}

Node* bst_inorder(Node* root)
{
    if (root == NULL)
        return;
    bst_inorder(root->left);
    printf("%d ", root->data);
    bst_inorder(root->right);
}

Node* bst_preorder(Node* root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    bst_preorder(root->left);
    bst_preorder(root->right);
}

Node* bst_postorder(Node* root)
{
    if (root == NULL)
        return;
    bst_preorder(root->left);
    bst_preorder(root->right);
    printf("%d ", root->data);
}

Node* bst_leftsubtree(Node* root)
{
    if (root == NULL)
        return;
    bst_preorder(root->left);
}

Node* bst_rightsubtree(Node* root)
{
    if (root == NULL)
        return;
    bst_preorder(root->right);
}

int main(void)
{
    Node* root = NULL;
    root = bst_insert(root, 8);
    bst_insert(root, 3);
    bst_insert(root, 10);
    bst_insert(root, 1);
    bst_insert(root, 6);
    bst_insert(root, 14);
    bst_insert(root, 4);
    bst_insert(root, 7);
    bst_insert(root, 13);
    
    bst_search(root, 10);
    printf("\n bst inorder:");
    bst_inorder(root);
    printf("\n bst preorder:");
    bst_preorder(root);
    printf("\n bst postorder:");
    bst_postorder(root);
    
    printf("\n bst leftsubtree:");
    bst_leftsubtree(root);
    
    printf("\n bst rightsubtree:");
    bst_rightsubtree(root);
    
    printf("\n bst leftview: ");
    bst_leftview(root);
    return 0;
}