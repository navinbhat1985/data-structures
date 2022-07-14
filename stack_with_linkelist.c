//gcc 7.4.0

#include  <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct stack {
    Node* top;
    Node* bottom;
    int len;
    int size;
} stack;

bool is_empty(stack* stk)
{
    if (!stk)
        return true;
    return (stk->len == 0);
}

bool is_full(stack* stk)
{
    if (!stk)
        return true;
    return (stk->len == stk->size);
}

stack* alloc_stack(int size)
{
   stack* stk = calloc(1, sizeof(stack));
   if (!stk)
       return NULL;
   stk->top = stk->bottom = NULL;
   stk->len = 0;
   stk->size = size;
   return stk;
}

void dealloc_stack(stack *stk)
{
    if (!stk)
        return;
    Node* cur = stk->top;
    Node* next = NULL;
    while (cur) {
        next = cur->next;
        free(cur);
        cur = next;
    }
    free(stk);
    return;
}

int push(stack* stk, int data)
{
    if (!stk)
        return -1;
    if (is_full(stk)) {
        printf("push %d failed: stack is full top %p size %d len %d\n", data, stk->top, stk->size, stk->len);
        return -1;
    }
    Node* new_node = calloc(1, sizeof(Node));
    new_node->data = data;
    new_node->next = stk->top;
    if (stk->top == NULL)
        stk->bottom = new_node;
    stk->top = new_node;
    stk->len++;
    return 0;
}

int pop(stack* stk)
{
    if (!stk)
        return -1;
    
    if (is_empty(stk)) {
        printf("pop failed: stack is empty top %p size %d len %d\n", stk->top, stk->size, stk->len);
        return -1;
    }
    Node* top = stk->top;
    stk->top = top->next;
    if (top == stk->bottom)
        stk->bottom = NULL;
    free(top);
    stk->len--;
    return (0);
}

int peek(stack* stk)
{
    if (!stk)
        return -1;
    if (is_empty(stk)) {
        printf("stack is empty\n");
    }
    return(stk->top->data);
}

int print_stack(stack *stk)
{
    if (!stk)
        return -1;
    printf("stack size %d top %p bottom %p len %d\n", stk->size, stk->top, stk->bottom, stk->len);
    Node* cur = stk->top;
    int i = 0;
    while (cur) {
        printf("stack[%d] = %d\n",i++, cur->data);
        cur = cur->next;
    }
    return 0;
}

int main(void)
{
    stack *stk = alloc_stack(10);
    push(stk, 1);
    push(stk, 2);
    push(stk, 3);
    push(stk, 4);
    push(stk, 5);
    
    printf("top item on stack is %d\n", peek(stk));
    print_stack(stk);
    
    push(stk, 6);
    push(stk, 7);
    push(stk, 8);
    push(stk, 9);
    push(stk, 10);
    push(stk, 11);
    
    printf("top item on stack is %d\n", peek(stk));    
    print_stack(stk);
    
    pop(stk);
    pop(stk);
    pop(stk);
    pop(stk);
    pop(stk);
    pop(stk);
    
    print_stack(stk);
    printf("top item on stack is %d\n", peek(stk));    
        
    pop(stk);
    pop(stk);
    pop(stk);
    pop(stk);
    pop(stk);
    print_stack(stk);
    return 0;
}