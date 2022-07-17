#include  <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct cir_queue {
    int *queue;
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
    c_q->queue = calloc(size, sizeof(int));
    c_q->size = size;
    c_q->len = 0;
    return c_q;
}

int cir_queue_enqueue(cir_queue* c_q, int data)
{
    if (!c_q)
        return -1;

    if (cir_queue_is_full(c_q)){
        printf("cir queue is full, cant enqueue %d\n", data);
        return -1;
    }
    c_q->queue[c_q->rear] = data;
    c_q->rear += 1;
    c_q->rear %= c_q->size;
    c_q->len++;
    return c_q->rear;
}

int cir_queue_dequeue(cir_queue* c_q)
{
    if (!c_q)
        return -1;
    if (cir_queue_is_empty(c_q)){
        printf("cir queue is empty\n");
        return -1;
    }
    int data = c_q->queue[c_q->front];
    c_q->front += 1;
    c_q->front %= c_q->size;
    c_q->len--;
    return (data);
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
        printf("%d ", c_q->queue[(c_q->front+i)%c_q->size]);
    }
    printf("\n");
}

int main(void)
{
    cir_queue *c_q = cir_queue_create(10);
    cir_queue_enqueue(c_q, 10);
    cir_queue_enqueue(c_q, 20);
    cir_queue_enqueue(c_q, 30);
    cir_queue_enqueue(c_q, 40);
    cir_queue_enqueue(c_q, 50);
    
    cir_queue_enqueue(c_q, 60);
    cir_queue_enqueue(c_q, 70);
    cir_queue_enqueue(c_q, 80);
    cir_queue_enqueue(c_q, 90);
    cir_queue_enqueue(c_q, 100);
    cir_queue_print(c_q);
    
    
    cir_queue_dequeue(c_q);
    cir_queue_dequeue(c_q);
    cir_queue_dequeue(c_q);
    cir_queue_dequeue(c_q);
    cir_queue_dequeue(c_q);
    cir_queue_print(c_q);
    
    cir_queue_dequeue(c_q);
    cir_queue_print(c_q);
    cir_queue_dequeue(c_q);
    cir_queue_print(c_q);
    cir_queue_dequeue(c_q);
    cir_queue_print(c_q);
    cir_queue_dequeue(c_q);
     
    cir_queue_enqueue(c_q, 10);
    cir_queue_enqueue(c_q, 20);
    cir_queue_enqueue(c_q, 30);
    cir_queue_enqueue(c_q, 40);
    cir_queue_enqueue(c_q, 50);
    
    cir_queue_enqueue(c_q, 60);
    cir_queue_enqueue(c_q, 70);
    cir_queue_enqueue(c_q, 80);
    cir_queue_enqueue(c_q, 90);
    printf("print all elemets\n");
    cir_queue_print(c_q);

    
    cir_queue_dequeue(c_q);
    cir_queue_dequeue(c_q);
    cir_queue_dequeue(c_q);
    cir_queue_dequeue(c_q);
    cir_queue_dequeue(c_q);
    cir_queue_print(c_q);    
    
    
        
    cir_queue_enqueue(c_q, 10);
    cir_queue_enqueue(c_q, 20);
    cir_queue_enqueue(c_q, 30);
    cir_queue_enqueue(c_q, 40);
    cir_queue_enqueue(c_q, 50);
    
    cir_queue_enqueue(c_q, 60);
    cir_queue_enqueue(c_q, 70);
    cir_queue_enqueue(c_q, 80);
    cir_queue_enqueue(c_q, 90);
    printf("print all elemets\n");
    cir_queue_print(c_q);

    return 0;
}