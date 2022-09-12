//gcc 7.4.0

#include  <stdio.h>
#include  <stdlib.h>

struct node {
   int data;
   struct node *left;
   struct node *right;
};
struct node *createNode(int val) {
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->data = val;
   temp->left = temp->right = NULL;
   return temp;
}
void inorder(struct node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf(" %d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root) {
    if (root == NULL)
        return;
    printf(" %d ", root->data);
    inorder(root->left);
    inorder(root->right);
}

void postorder(struct node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    inorder(root->right);
    printf(" %d ", root->data);
}

struct node* insertNode(struct node* root, int val) {
    if (root == NULL) {
        struct node* node = createNode(val);
        return node;
    }
    
    if (val <= root->data) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

int count = 0;
    
void printKthSmallest(struct node* root, int k)
{
    if (root == NULL) {
        return ;
    }
    printKthSmallest(root->left, k);
    count++;
    if (count == k) {
        printf("\n%dth smallest element is %d\n",k, root->data);
        return ;
    }
    printKthSmallest(root->right, k);
    return ;
}

int kth_smallest(struct node* root, int k, int cnt)
{
    if (root == NULL) {
        return cnt;
    }
    cnt = kth_smallest(root->left, k, cnt);
    cnt++;
    if (cnt == k)
        printf("\n%dth smallest element is %d\n",k, root->data);
    cnt = kth_smallest(root->right, k, cnt);
    return cnt;
}

int kth_largest(struct node* root, int k, int cnt)
{
    if (root == NULL) {
        return cnt;
    }
    cnt = kth_largest(root->right, k, cnt);
    cnt++;
    if (cnt == k)
        printf("\n%dth largest element is %d\n", k, root->data);
    cnt = kth_largest(root->left, k, cnt);
    return cnt;
}

void printKthLargest(struct node* root, int k)
{
    if (root == NULL) {
        return ;
    }
    printKthLargest(root->right, k);
    count++;
    if (count == k) {
        printf("\n%dth Largest element is %d\n",k, root->data);
        return ;
    }
    printKthLargest(root->left, k);
    return ;
}


int main() {
   struct node *root = NULL;
   root = insertNode(root, 4);
   insertNode(root, 5);
   insertNode(root, 2);
   insertNode(root, 9);
   insertNode(root, 1);
   insertNode(root, 3);
   printf("\nIn-Order traversal of the Binary Search Tree is: \n");
   inorder(root);
   printf("\nPre-Order traversal of the Binary Search Tree is: \n");
   preorder(root);
   printf("\nPost-Order traversal of the Binary Search Tree is: \n");
   postorder(root);
    //count = 0;
    //printKthSmallest(root, 3);
    printf("\nno.of items in BST %d\n" ,kth_smallest(root, 2, 0));
    
    //count = 0;
    //printKthLargest(root, 5);
   printf("\nno.of items in BST %d\n" ,kth_largest(root, 2, 0));
   return 0;
}