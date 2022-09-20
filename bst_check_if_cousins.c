#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// A Binary Tree Node 
typedef struct Node { 
    int data; 
    struct Node *left, *right; 
}Node; 
  
// A utility function to create a new 
// Binary Tree Node 
struct Node* newNode(int item) 
{ 
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

typedef struct result {
    Node* parent;
    int height;
} result;

int get_height(Node* root, Node* a, int height)
{
    if (root == NULL)
        return 0;
    if (root == a) {
        return height;
    }
    int ret = get_height(root->left, a, height+1);
    if (ret != 0) {
         return ret;
    }
    ret = get_height(root->right, a, height+1);
    return ret;
}

int get_result(Node* root, Node* a, int height, result *res)
{
    if (root == NULL)
        return 0;
    if (root == a) {
        return height;
    }
    int ret = get_result(root->left, a, height+1, res);
    if (ret != 0) {
        res->height = ret;
        res->parent = root;
        return 0;
    }
    ret = get_result(root->right, a, height+1, res);
    if (ret != 0) {
        res->height = ret;
        res->parent = root;
        return 0;
    }
}

int get_parents(Node* root, Node* a, Node* b, int height, result *res1, result* res2)
{
    if (root == NULL)
        return 0;
    if (root == a || root == b) {
        return height;
    }
    int ret = get_parents(root->left, a, b, height+1, res1, res2);
    if (ret != 0) {
        if (res1->height == 0) {
            res1->height = ret;
            res1->parent = root;
        } else if (res2->height == 0) {
            res2->height = ret;
            res2->parent = root;
        }
        ret = 0;
    }
    ret = get_parents(root->right, a, b, height+1, res1, res2);
    if (ret != 0) {
        if (res1->height == 0) {
            res1->height = ret;
            res1->parent = root;
        } else if (res2->height == 0) {
            res2->height = ret;
            res2->parent = root;
        }
        ret = 0;
    }
    return ret;
}

bool same_parents(Node* root, Node* a, Node* b)
{
    if (root == NULL)
        return false;
    return ((root->left == a && root->right == b) || (root->left == b && root->right == a) || 
             same_parents(root->left, a, b) || same_parents(root->right, a, b));
}

// Returns true if a and b are cousins, 
// otherwise false. 
int isCousinFound(Node* root, Node* a, Node* b) 
{
    if (root == NULL)
        return false;
    int h1 = get_height(root, a, 0);
    int h2 = get_height(root, b, 0);
    if (h1 == h2) {
        printf("%d and %d have same height h1 %d h2 %d\n", a->data, b->data, h1, h2);
        if (!same_parents(root, a, b)) {
            printf("%d and %d are cousins\n", a->data, b->data);
        } else {
            printf("%d and %d are not cousins\n", a->data, b->data);
        }
    } else {
        printf("%d and %d are at not cousins due to height difference h1 %d h2 %d\n", a->data, b->data, h1, h2);
    }
    /*result res1 = {0};
    result res2 = {0};
    //get_result(root, a, 0,  &res1);
    //get_result(root, b, 0, &res2);
    //get_parents(root, a, b, 0, &res1, &res2);
    if (res1.height == res2.height && res1.parent != res2.parent) {
        printf("%d and %d are cousins h1 %d h2 %d parent1 %d parent2 %d\n", a->data, b->data, res1.height, res2.height, res1.parent->data, res2.parent->data);
    } else {
        printf("%d and %d are not cousins h1 %d h2 %d parent1 %d parent2 %d\n", a->data, b->data, res1.height, res2.height, res1.parent->data, res2.parent->data);
    }*/
} 

int main() 
{ 
    /* 
            1  
           /  \  
          2    3 
         / \  / \ 
        4   5 6  7 
             \ \ 
             15 8 
    */
  
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->right->right = newNode(15); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
  
    struct Node *Node1, *Node2; 
    Node1 = root->left->left; 
    Node2 = root->left->right; 
  
    isCousinFound(root, Node1, Node2); 
  
    return 0; 
} 