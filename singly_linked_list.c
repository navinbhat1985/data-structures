#include  <stdio.h>
#include  <stdlib.h>
#include  <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct sll {
    Node* head;
    Node* tail;
    int len;
}sll;

Node* sll_prepend(sll* slist, int data)
{
    if (!slist)
        return NULL;
    
    Node* head = slist->head;
    Node* new_node = calloc(1, sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    if (NULL == slist->tail)
        slist->tail = new_node;
    slist->head = new_node;
    slist->len++;
    return slist->head;
}

Node* sll_append(sll* slist, int data)
{
    if (!slist)
        return NULL;
    
    Node* head = slist->head;
    Node* tail = slist->tail;
    Node* new_node = calloc(1, sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (tail != NULL) {
        tail->next = new_node;
    }
    if (NULL == head)
        slist->head = new_node;
    slist->tail = new_node;
    slist->len++;
    return slist->tail;
}

int sll_find(sll *slist, int data)
{
    bool found = false;
    if (!slist)
        return -1;
    Node* cur = slist->head;
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

int sll_remove(sll *slist, int data)
{
    int ret = 0;
    if (!slist)
        return -1;
    Node* head = slist->head;
    Node* cur = head;
    Node* prev = NULL;
    int index = 0;
    while (cur) {
        if (cur->data == data) {
            if (prev) {
                prev->next = cur->next;
            }
            if (cur == slist->head)
                slist->head = cur->next;
            if (cur == slist->tail)
                slist->tail = prev;
            slist->len--;
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

int sll_length(sll* slist)
{
    if (!slist)
        return 0;
    printf("SLL length\t: %3d\n", slist->len);
    return slist->len;
}

void sll_print(sll* slist)
{
    if (!slist)
        return;
    Node* head = slist->head;
    if (NULL == head)
        return;
    
    Node* cur = head;
    printf("SLL Items\t: ");
    while (cur) {
        printf("%3d\t", cur->data);
        cur = cur->next;
    }
    printf("\n");
}


int main(void)
{
    sll dlist = {NULL, NULL, 0};
    
    sll_append(&dlist, 60);
    sll_append(&dlist, 70);
    sll_append(&dlist, 80);
    sll_append(&dlist, 90);
    sll_append(&dlist, 100);

    
    sll_prepend(&dlist, 50);
    sll_prepend(&dlist, 40);
    sll_prepend(&dlist, 30);
    sll_prepend(&dlist, 20);
    sll_prepend(&dlist, 10);

    
    sll_append(&dlist, 110);
    sll_append(&dlist, 120);
    
    sll_length(&dlist);
    sll_print(&dlist);
    
    sll_remove(&dlist, 100);
    sll_length(&dlist);
    sll_print(&dlist);
    
    sll_remove(&dlist, 10);
    sll_length(&dlist);
    sll_print(&dlist);

    sll_remove(&dlist, 120);
    sll_length(&dlist);
    sll_print(&dlist);

    return 0;
}