#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 

typedef struct node 
{ 
    int data; 
    struct node *left, *right; 
}node; 

typedef struct result {
    bool found;
    node* parent;
    int height;
} result;

bool is_left = false;

bool find_node(node* root, node* target, int *height, node** parent)
{
    if (root == NULL || target == NULL)
        return false;
    if (root->data == target->data)
        return true;
    int tmp = *height+1;
    *parent = root;
    bool found = find_node(root->left, target, &tmp, parent);
    if (false == found) {
        found = find_node(root->right, target, &tmp, parent);
        is_left = false;
    } else {
        is_left = true;
    }
    if (found) {
        *height = tmp;
    }
    return found;
}
void print_nodes_at_distance(node* node, int k)
{
    if (node == NULL || k < 0)
        return;
    if (k == 0)
        printf(" %d ", node->data);
    print_nodes_at_distance(node->left, k-1);
    print_nodes_at_distance(node->right, k-1);
    return;
}
// Prints all nodes at distance k from a given target node. 
// The k distant nodes may be upward or downward.  This function 
// Returns distance of root from target node, it returns -1 if target 
// node is not present in tree rooted with root. 
int printkdistanceNode(node* root, node* target , int k) 
{
    if (root == NULL)
        return 0;
    if (target == NULL)
        return 0;
    int height = 0;
    node* parent = NULL;
    bool found = find_node(root, target, &height, &parent);
    if (!found) {
        printf("\nDint find the node %d in root %d\n", target->data, root->data);
        return -1;
    }
    printf("\nFound the node %d, its parent %d at height %d from root %d\n", target->data, parent->data, height, root->data);
    printf("\nNodes at distance %d from target %d are: ", k, target->data);
    print_nodes_at_distance(target, k);
    printf("\n");
    printf("\nNodes at distance %d from parent %d are: ", k, target->data);
    if (parent->left == target) {
        print_nodes_at_distance(parent->right, k-2);
    } else {
        print_nodes_at_distance(parent->left, k-2);
    }
    printf("\n");
    if (is_left) { //target->data < root->data) {
        printf("\ntarget %d is on the left side of the root %d\n", target->data, root->data);
        printf("\nNodes at distance %d from root %d are: ", k, target->data);
        print_nodes_at_distance(root->right, k-height-1);
    } else {
        printf("\ntarget %d is on the right side of the root %d\n", target->data, root->data);
        printf("\nNodes at distance %d from root %d are: ", k, target->data);
        print_nodes_at_distance(root->left, k-height-1);
    }
    return 0;
} 
   
node *newnode(int data) 
{ 
    node *temp = calloc(1, sizeof(node)); 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf(" %d ", root->data);
    inorder(root->right);
}

node* insert_node(node* root, node* new_node)
{
   if (root == NULL)
       return NULL;
    if (new_node->data < root->data) {
        if (root->left != NULL) {
           insert_node(root->left, new_node);
        } else {
            root->left = new_node;
        }
    } else {
        if (root->right != NULL) {
           insert_node(root->right, new_node);
        } else {
            root->right = new_node;
        }
    }
    return new_node;
}
  
int main() 
{ 
    
    /*node * root = newnode(1); 
    node* target = insert_node(root, newnode(2)); 
    insert_node(root, newnode(3)); 
    insert_node(root, newnode(7)); 
    insert_node(root, newnode(6)); 
    insert_node(root, newnode(5)); 
    insert_node(root, newnode(4));
    insert_node(root, newnode(17));
    insert_node(root, newnode(8));
    printf("BST: ");
    inorder(root);
    printf("\n");*/
    
   /*  node * root = newnode(22); 
    root->left = newnode(18); 
    root->right = newnode(23); 
    root->left->left = newnode(14); 
    root->left->right = newnode(11); 
    root->left->right->left = newnode(9); 
    root->left->right->right = newnode(10); 
    node * target = root->left->right; */
    
    node * root = newnode(1); 
    root->left = newnode(2); 
    root->right = newnode(3); 
    root->left->left = newnode(7); 
    root->left->right = newnode(6); 
    root->left->right->left = newnode(17); 
    root->right->left = newnode(5); 
    root->right->right = newnode(4); 
    root->right->right->right = newnode(8); 
    node * target = root->right->right;
    
    int k = 2;
    printkdistanceNode(root, target, k); 
    return 0; 
}