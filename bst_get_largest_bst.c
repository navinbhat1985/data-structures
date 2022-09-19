#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MIN(a,b) ((a < b) ? a : b)
#define MAX(a,b) ((a > b) ? a : b)

typedef struct node  
{  
    int data;  
    struct node* left;
    struct node* right;  
}node;

typedef struct result {
    int size;
    int min;
    int max;
    bool valid;
} result;

node* new_node(int data)
{
    node* n = calloc(1, sizeof(node));
    n->data = data;
    return n;
}

int max_size = 0;

result largestBST(node* node)  
{
    result res = {0};
    if (node == NULL) {
        res.size = 0; res.min = INT_MAX; res.max = INT_MIN; res.valid = true;
        return res;
    }
    if (node->left == NULL && node->right == NULL) {
        res.size = 1; res.min = node->data; res.max = node->data; res.valid = true;
        return res;
    }
    
    result left = largestBST(node->left);
    result right = largestBST(node->right);

        
    res.valid = false;
    if (left.valid && right.valid  && left.max < node->data && right.min > node->data) {
        res.valid = true;
        res.min = left.min;
        res.max = right.max;
        res.size = (1 + left.size + right.size);
    }
    if (res.valid && res.size > max_size) {
        max_size = res.size;
        printf("\nBST found at root %d of size %d", node->data, max_size);
    } else if (left.valid && left.size > max_size) {
        max_size = left.size;
        printf("\nBST found at root %d of size %d", node->left->data, max_size);
    } else if (right.valid && right.size > max_size) {
        max_size = right.size;
        printf("\nBST found at root %d of size %d", node->right->data, max_size);
    }
    return res;
}  
  
int main()  
{  
        /* Let us construct the following Tree  
        50  
        / \  
        10 60  
        / \ / \  
      5 20 55 70  
        / / \  
       45 65 80  
    */
      
    node *root = new_node(50);  
    root->left = new_node(10);  
    root->right = new_node(60);  
    root->left->left = new_node(5);  
    root->left->right = new_node(20);  
    root->right->left = new_node(55);  
    root->right->left->left = new_node(45);  
    root->right->right = new_node(70);  
    root->right->right->left = new_node(65);  
    root->right->right->right = new_node(80);  
      
    /* The complete tree is not BST  
    as 45 is in right subtree of 50.  
    The following subtree is the largest BST  
        60  
        / \  
       55 70  
        / / \  
    45 65 80  
    */
    largestBST(root);
    return 0;  
}  