#include  <stdio.h>
#include  <stdlib.h>
#include  <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct queue {
    Node* front;
    Node* rear;
    int len;
    int size;
} queue;

bool is_empty(queue *q)
{
    if (!q)
        return false;
    return (q->len == 0);
}

bool is_full(queue *q)
{
    if (!q)
        return true;
    return (q->size == q->len);
}

queue* alloc_queue(int size)
{
    queue* q = calloc(1, sizeof(queue));
    q->front = q->rear = NULL;
    q->size = size;
    q->len = 0;
    return q;
}

int enqueue(queue* q, int data)
{
    if (!q)
        return -1;
    
    if(is_full(q)) {
        printf("enqueue failed: queue is full front %p rear %p len %d size %d\n", q->front, q->rear, q->len, q->size);
        return -1;
    }
    Node* new_node = calloc(1, sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (q->front == NULL)
        q->front = new_node;
    if (q->rear != NULL)
        q->rear->next = new_node;
    q->rear = new_node;
    q->len++;
    return 0;
}

int dequeue(queue* q)
{
    if (!q)
        return -1;

    if(is_empty(q)) {
        printf("dequeue failed: queue is empty front %p rear %p len %d size %d\n", q->front, q->rear, q->len, q->size);
        return -1;
    }
    Node* front = q->front;
    q->front = front->next;
    if (q->front == NULL)
        q->front = q->rear = NULL;
    free(front);
    q->len--;
    return 0;
}

void print_queue(queue* q)
{
    if (!q)
        return;
     
    if(is_empty(q)) {
        printf("queue is empty front %p rear %p len %d size %d\n", q->front, q->rear, q->len, q->size);
        return;
    }
    Node* front = q->front;
    int i = 0;
    while(front) {
        printf("q[%d]=%d\n", i, front->data);
        front = front->next;
    }
    return;
}

int peek(queue *q)
{
    if (!q)
        return -1;
     
    if(is_empty(q)) {
        printf("queue is empty front %p rear %p len %d size %d\n", q->front, q->rear, q->len, q->size);
        return -1;
    }
    Node* front = q->front;
    return front->data;
}


int main(void)
{
    queue *q = alloc_queue(10);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    
    printf("front item on queue is %d\n", peek(q));
    print_queue(q);

    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);
    enqueue(q, 10);
    
    printf("front item on queue is %d\n", peek(q));    
    print_queue(q);
    
    enqueue(q, 11);

    printf("dequeue items from the queue\n");
    
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    
    print_queue(q);
    printf("front item on queue is %d\n", peek(q));    
    
    printf("dequeue items from the queue\n");
    dequeue(q);
    dequeue(q);
    dequeue(q);
    
    print_queue(q);
    
    dequeue(q);
    dequeue(q);
    print_queue(q);
    
    dequeue(q);
    return 0;
}