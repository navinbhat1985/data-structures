//gcc 7.4.0

#include  <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
    int* array;
    int size;
    int top;
    int bottom;
    int len;
} stack;

bool is_empty(stack* stk)
{
    if (!stk || !stk->array)
        return -1;
    return (stk->top == stk->bottom);
}

bool is_full(stack* stk)
{
    if (!stk || !stk->array)
        return true;
    return (stk->top == stk->size);
}

stack* create_stack(int size)
{
   stack* stk = calloc(1, sizeof(stack));
   if (!stk)
       return NULL;

   stk->array = calloc(size, sizeof(int));
   if(!stk->array) {
        free(stk);
        return NULL;
   }
   stk->top = stk->bottom = 0;
   stk->len = 0;
   stk->size = size;
   return stk;
}

int push(stack* stk, int data)
{
    if (!stk || !stk->array)
        return -1;
    if (is_full(stk)) {
        printf("push %d failed: stack is full top %d size %d len %d\n", data, stk->top, stk->size, stk->len);
        return -1;
    }
    stk->array[stk->top++] = data;
    stk->len++;
    return 0;
}

int pop(stack* stk)
{
    if (!stk || !stk->array)
        return -1;
    
    if (is_empty(stk)) {
        printf("pop failed: stack is empty top %d size %d len %d\n", stk->top, stk->size, stk->len);
        return -1;
    }

    stk->len--;
    return (stk->array[--stk->top]);
}

int peek(stack* stk)
{
    if (!stk || !stk->array)
        return -1;
    return(stk->array[stk->top-1]);
}

int print_stack(stack *stk)
{
    if (!stk || !stk->array)
        return -1;
    printf("stack size %d top %d bottom %d len %d\n", stk->size, stk->top, stk->bottom, stk->len);
    for(int i = stk->top-1; i >= stk->bottom; i--){
        printf("stack[%d] = %d\n",i, stk->array[i]);
    }
}

int main(void)
{
    stack* stk = create_stack(10);
    push(stk, 1);
    push(stk, 2);
    push(stk, 3);
    push(stk, 4);
    push(stk, 5);
    
    printf("top item on stacks is %d\n", peek(stk));
    
    push(stk, 6);
    push(stk, 7);
    push(stk, 8);
    push(stk, 9);
    push(stk, 10);
    push(stk, 11);
    
    printf("top item on stacks is %d\n", peek(stk));    
    print_stack(stk);
    
    pop(stk);
    pop(stk);
    pop(stk);
    pop(stk);
    pop(stk);
    pop(stk);
    
    printf("top item on stacks is %d\n", peek(stk));    
        
    pop(stk);
    pop(stk);
    pop(stk);
    pop(stk);
    pop(stk);
    print_stack(stk);
    return 0;
}