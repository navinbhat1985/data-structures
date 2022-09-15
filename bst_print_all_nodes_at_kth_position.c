#include <stdio.h>
#include <stdlib.h>

typedef struct node  
{  
    int data;  
    struct node* left;  
    struct node* right;  
}node;  

node* new_node(int data)
{
    node* Node = calloc(1, sizeof(node));
    Node->data = data;
    return Node;
}

void printKDistance(node *root , int k, int h)  
{
    if (root == NULL)
        return;
    if (h == k) {
        printf("node at %d distance is %d\n", k, root->data);
        return;
    }
    printKDistance(root->left, k, h+1);
    printKDistance(root->right, k, h+1);
}  
  
  

int main()  
{  
  
  
    /*node *root = new_node(1);  
    root->left = new_node(2);  
    root->right = new_node(3);  
    root->left->left = new_node(4);  
    root->left->right = new_node(5);  
    root->right->left = new_node(8);  */
    
    node* root = new_node(10);
    root->left = new_node(12);
    root->right = new_node(3);
    root->left->right = new_node(4);
    root->right->left = new_node(5);
    root->right->left->right = new_node(6);
      
    printKDistance(root, 2, 0);  
    return 0;  
}  

/* Try more Inputs

/* Constructed binary tree is           
             1  
            / \  
           2   3  
          / \ /  
         4  5 8  
    */
/*Case 1:
Main tree = new Main(); 
tree.root = new Node(1);  
tree.root.left = new Node(2);  
tree.root.right = new Node(3);  
tree.root.left.left = new Node(4);  
tree.root.left.right = new Node(5);  
tree.root.right.left = new Node(8); 
tree.printLeftView(tree.root,2)
expected = [4,5,8]*/

//Case2: 
/* Constructed binary tree is           
             10  
            / \  
           12  3  
           \  /  
            4 5  
                \
                 6
*/
/*BinaryTree root = newNode(10);
root.left = newNode(12);
root.right = newNode(3);
root.left.right = newNode(4);
root.right.left = newNode(5);
root.right.left.right = newNode(6);
tree.printLeftView(root,2)
expected = [4,5]
*/