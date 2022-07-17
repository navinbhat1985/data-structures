#include  <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct cir_queue {
    Node** queue;
    int rear;
    int front;
    int size;
    int len;
} cir_queue;

bool cir_queue_is_full(cir_queue* c_q)
{
    if (!c_q)
        return true;
    return(((c_q->rear+1) % c_q->size) == (c_q->front  % c_q->size));
}

bool cir_queue_is_empty(cir_queue* c_q)
{
    if (!c_q)
        return false;
    return (c_q->front == c_q->rear);
}

cir_queue* cir_queue_create(int size)
{
    if (size == 0)
        return NULL;
    cir_queue *c_q = calloc(1, sizeof(cir_queue));
    c_q->rear = c_q->front = 0;
    c_q->queue = calloc(size, sizeof(Node*));
    c_q->size = size;
    c_q->len = 0;
    return c_q;
}

int cir_queue_enqueue(cir_queue* c_q, Node* node)
{
    if (!c_q)
        return -1;

    if (cir_queue_is_full(c_q)){
        printf("cir queue is full, cant enqueue %p\n", node);
        return -1;
    }
    c_q->queue[c_q->rear] = node;
    c_q->rear += 1;
    c_q->rear %= c_q->size;
    c_q->len++;
    return c_q->rear;
}

Node* cir_queue_dequeue(cir_queue* c_q)
{
    if (!c_q)
        return NULL;
    if (cir_queue_is_empty(c_q)){
        printf("cir queue is empty\n");
        return NULL;
    }
    Node* node = c_q->queue[c_q->front];
    c_q->front += 1;
    c_q->front %= c_q->size;
    c_q->len--;
    return (node);
}

void cir_queue_print(cir_queue* c_q)
{
    if (!c_q)
        return;
    if (cir_queue_is_empty(c_q)){
        printf("cir queue is empty\n");
        return;
    }
    printf("\nQueue front %d rear %d size %d len %d\n", c_q->front, c_q->rear, c_q->size, c_q->len);
    for (int i = 0; i < c_q->len; i++) {
        printf("%p ", c_q->queue[(c_q->front+i)%c_q->size]);
    }
    printf("\n");
}

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

void bst_inorder(Node* root)
{
    if (root == NULL)
        return;
    bst_inorder(root->left);
    printf("%d ", root->data);
    bst_inorder(root->right);
}

void bst_preorder(Node* root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    bst_preorder(root->left);
    bst_preorder(root->right);
}

void bst_postorder(Node* root)
{
    if (root == NULL)
        return;
    bst_preorder(root->left);
    bst_preorder(root->right);
    printf("%d ", root->data);
}

void bst_leftsubtree(Node* root)
{
    if (root == NULL)
        return;
    bst_preorder(root->left);
}

void bst_rightsubtree(Node* root)
{
    if (root == NULL)
        return;
    bst_preorder(root->right);
}

void bst_bfs_print(Node* root, cir_queue* c_q)
{
    if (!c_q)
        return;
    if (root == NULL) {
        return;
    }
    cir_queue_enqueue(c_q, root);
    printf("\nBST BFS print output: ");
    while (!cir_queue_is_empty(c_q)) {
        Node* cur = cir_queue_dequeue(c_q);
        if (cur->left) {
            cir_queue_enqueue(c_q, cur->left);
        }
        if (cur->right) {
            cir_queue_enqueue(c_q, cur->right);
        }
        printf("%d ", cur->data);
    }
}


void bst_bfs_print_r(cir_queue* c_q)
{
    if (!c_q)
        return;
    
    if (cir_queue_is_empty(c_q)){
        printf("\ncir_queue is empty\n");
        return;
    }
    
    Node* cur = cir_queue_dequeue(c_q);
    if (!cur) {
        printf("cir_queue dequeue node ptr is NULL\n");
        return;
    }

    printf("%d ", cur->data);
    if (cur->left)
        cir_queue_enqueue(c_q, cur->left);
    if (cur->right)
        cir_queue_enqueue(c_q, cur->right);
    bst_bfs_print_r(c_q);
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
    printf("\nbst inorder:");
    bst_inorder(root);
    
    cir_queue *c_q = cir_queue_create(100);
    bst_bfs_print(root, c_q);
    
    printf("\nBST BFS recursive output:");
    cir_queue_enqueue(c_q, root);
    bst_bfs_print_r(c_q);
    printf("\n");
    
    return 0;
}