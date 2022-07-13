#include  <stdio.h>
#include  <stdlib.h>
#include  <stdbool.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct dll {
    Node* head;
    Node* tail;
    int len;
}dll;

Node* dll_prepend(dll* dlist, int data)
{
    if (!dlist)
        return NULL;
    
    Node* head = dlist->head;
    Node* new_node = calloc(1, sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    new_node->prev = NULL;
    if (head != NULL) {
        head->prev = new_node;
    }
    if (NULL == dlist->tail)
        dlist->tail = new_node;
    dlist->head = new_node;
    dlist->len++;
    return dlist->head;
}

Node* dll_append(dll* dlist, int data)
{
    if (!dlist)
        return NULL;
    
    Node* head = dlist->head;
    Node* tail = dlist->tail;
    Node* new_node = calloc(1, sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = tail;
    if (tail != NULL) {
        tail->next = new_node;
    }
    if (NULL == head)
        dlist->head = new_node;
    dlist->tail = new_node;
    dlist->len++;
    return dlist->tail;
}


int dll_find(dll *dlist, int data)
{
    bool found = false;
    if (!dlist)
        return -1;
    Node* cur = dlist->head;
    int index = 0;
    while (cur) {
        if (cur->data == data) {
            found = true;
            break;
        }
        cur = cur->next;
        index++;
    }
    if (!found)
        return -1;
    return index;
}

int dll_remove(dll *dlist, int data)
{
    int ret = 0;
    if (!dlist)
        return -1;
    Node* head = dlist->head;
    Node* cur = head;
    Node* prev = NULL;
    int index = 0;
    while (cur) {
        if (cur->data == data) {
            if (prev) {
                prev->next = cur->next;
            }
            if (cur->next) {
                cur->next->prev = prev;
            }
            if (cur == head) 
                dlist->head = cur->next;
            if (cur == dlist->tail)
                dlist->tail = prev;
            dlist->len--;
            free(cur);
            printf("Remove data %d at index %d\n", data, index);
            break;
        }
        prev = cur;
        cur = cur->next;
        index++;
    }
    return ret;
}

int dll_length(dll* dlist)
{
    if (!dlist)
        return 0;
    printf("DLL length\t: %d\n", dlist->len);
    return dlist->len;
}

void dll_print_forward(dll* dlist)
{
    if (!dlist)
        return;
    Node* head = dlist->head;
    if (NULL == head)
        return;
    
    Node* cur = head;
    printf("DLL Items\t: ");
    while (cur) {
        printf("%3d\t", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void dll_print_backward(dll* dlist)
{
    if (!dlist)
        return;
    Node* tail = dlist->tail;
    if (NULL == tail)
        return;
    
    Node* cur = tail;
    printf("DLL backward\t: ");
    while (cur) {
        printf("%3d\t", cur->data);
        cur = cur->prev;
    }
    printf("\n");
}


int main(void)
{
    dll dlist = {NULL, NULL, 0};
    
    dll_append(&dlist, 60);
    dll_append(&dlist, 70);
    dll_append(&dlist, 80);
    dll_append(&dlist, 90);
    dll_append(&dlist, 100);

    
    dll_prepend(&dlist, 50);
    dll_prepend(&dlist, 40);
    dll_prepend(&dlist, 30);
    dll_prepend(&dlist, 20);
    dll_prepend(&dlist, 10);

    
    dll_append(&dlist, 110);
    dll_append(&dlist, 120);
    
    dll_length(&dlist);
    dll_print_forward(&dlist);
    dll_print_backward(&dlist);
    
    dll_remove(&dlist, 100);
    dll_length(&dlist);
    dll_print_forward(&dlist);
    
    dll_remove(&dlist, 10);
    dll_length(&dlist);
    dll_print_forward(&dlist);

    dll_remove(&dlist, 120);
    dll_length(&dlist);
    dll_print_forward(&dlist);

    return 0;
}