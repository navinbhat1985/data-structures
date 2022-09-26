#include <stdio.h> 
#include <stdlib.h> 
   
typedef struct Node 
{ 
    int data; 
    struct Node *right; 
    struct Node *down; 
} Node; 
  
Node* push_down(Node** headPtr, int data) 
{
    Node* node = calloc(1, sizeof(Node));
    node->data = data;
    node->down = *headPtr;
    *headPtr = node;
    return node;
} 

Node* push_right(Node** headPtr, int data) 
{ 
    Node* node = calloc(1, sizeof(Node));
    node->data = data;
    node->right = *headPtr;
    *headPtr = node;
    return node;
} 

/* Function to print nodes in the flattened linked list */
void print_right(Node *node) 
{ 
    while (node) {
        printf("%d -> ", node->data);
        node = node->right;
    }
    printf("NULL\n");
} 

void print_down(Node *node) 
{ 
    while (node) {
        printf("%d -> ", node->data);
        node = node->down;
    }
    printf("NULL\n");
} 
  
//function to merge two sorted linked lists 
Node* merge(Node* a, Node* b) 
{ 
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    a->right = b->right;
    b->right = NULL;
    Node* cur1 = a;
    Node* cur2 = b;
    Node* prev = NULL;
    while(cur1 && cur2) {
        if (cur1->data >= cur2->data) {
            if (prev == NULL) {
                a = prev = cur2;
                cur2 = cur2->down;
                prev->down = cur1;
            } else {
                prev->down = cur2;
                prev = cur2;
                cur2 = cur2->down;
                prev->down = cur1;
            }
        } else {
            prev = cur1;
            cur1 = cur1->down;
        }
    }
    if (cur2) {
        prev->down = cur2;
    }
    return a;
} 
  
//Main function that flattens a given linked list 
Node* flatten (Node* root) 
{
    if (root == NULL)
        return NULL;
    while (root->right) {
        root = merge(root, root->right);
    }
    return root;
} 
  
int main() 
{ 
    Node* root = NULL; 
  
    /* Let us create the following linked list 
       5 -> 10 -> 19 -> 28 
       |    |     |     | 
       V    V     V     V 
       7    20    22    35 
       |          |     | 
       V          V     V 
       8          50    40 
       |                | 
       V                V 
       30               45 
    */
    push_down( &root, 30 ); 
    push_down( &root, 8 ); 
    push_down( &root, 7 ); 
    push_down( &root, 5 ); 
    print_down(root); 
  
    push_down( &( root->right ), 20 ); 
    push_down( &( root->right ), 10 ); 
    print_down(root->right); 
  
    push_down( &( root->right->right ), 50 ); 
    push_down( &( root->right->right ), 22 ); 
    push_down( &( root->right->right ), 19 ); 
    print_down(root->right->right); 
    
    push_down( &( root->right->right->right ), 45 ); 
    push_down( &( root->right->right->right ), 40 ); 
    push_down( &( root->right->right->right ), 35 ); 
    push_down( &( root->right->right->right ), 28 ); 
    print_down(root->right->right->right);
  
    print_right(root);
    
    // Let us flatten the list 
    root = flatten(root); 
    printf("\n Flattened list: ");
    print_down(root);
    // Let us print the flatened linked list 
     
  
    return 0; 
} 
