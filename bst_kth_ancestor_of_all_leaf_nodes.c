#include<stdio.h>  
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} node;

typedef struct ancestor{
  node* node;
  bool visited;
}ancestor;

int print_leaf_nodes(node* root, int k, ancestor* ans, int index)
{
    if (root == NULL)
        return -1;
    if (root->left == NULL && root->right == NULL) {
        printf("leaf node %d index %d ", root->data, index);
        if (index+1 >= k) {
            if (!ans[index+1-k].visited) {
                printf("New node %d -> anscestor[%d] = %d at distance %d\n", root->data, index, ans[index+1-k].node->data, k); 
                ans[index+1-k].visited = true;
            } else {
                printf("Old node %d -> anscestor[%d] = %d\n", root->data, index, ans[index+1-k].node->data, k); 
            }
        }
        return 0;
    }
    ans[index+1].node = root;
    print_leaf_nodes(root->left, k, ans, index+1);
    print_leaf_nodes(root->right, k, ans, index+1);
    return 0;
}

int get_depth(node* root)
{
    if (root == NULL)
        return -1;
    if (root->left == NULL && root->right == NULL)
        return 0;
    int ldepth = get_depth(root->left) + 1;
    int rdepth = get_depth(root->right) + 1;
    if (ldepth > rdepth)
        return ldepth;
    else
        return rdepth;
}

node *newnode(int data)
{
    node *temp = calloc(1, sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
    node * root = newnode(22);
    root->left = newnode(18);
    root->right = newnode(23);
    root->left->left = newnode(14);
    root->left->right = newnode(11);
    root->left->right->left = newnode(9);
    root->left->right->right = newnode(10);
    node * target = root->left->right;
    ancestor *ans = calloc(100, sizeof(ancestor));
    printf("\n Depth of the tree is %d\n", get_depth(root));
    print_leaf_nodes(root, 2, ans, -1);
    return 0;
}
