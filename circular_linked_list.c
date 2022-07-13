#include  <stdio.h>
#include  <stdlib.h>
#include  <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct cll {
    Node* head;
    Node* tail;
    int len;
}cll;

Node* cll_prepend(cll* clist, int data)
{
    if (!clist)
        return NULL;

    Node* head = clist->head;
    Node* new_node = calloc(1, sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    if (NULL == clist->tail)
        clist->tail = new_node;
    clist->head = new_node;
    clist->tail->next = new_node;
    clist->len++;
    return clist->head;
}

Node* cll_append(cll* clist, int data)
{
    if (!clist)
        return NULL;
    
    Node* head = clist->head;
    Node* tail = clist->tail;
    Node* new_node = calloc(1, sizeof(Node));
    new_node->data = data;
    if (NULL == head)
        clist->head = new_node;
    if (NULL == tail) {
        new_node->next = clist->head;
    } else {
        new_node->next = tail->next;
        tail->next = new_node;
    }
    clist->tail = new_node;
    clist->len++;
    return clist->tail;
}

int cll_find(cll *clist, int data)
{
    bool found = false;
    if (!clist)
        return -1;
    Node* head = clist->head;
    Node* cur = head;
    int index = 0;
    while (cur) {
        if (cur->data == data) {
            found = true;
            break;
        }
        cur = cur->next;
        if (cur == head)
            break;
        index++;
    }
    if (!found)
        return -1;
    return index;
}


int cll_remove(cll *clist, int data)
{
    int ret = 0;
    bool found = false;
    if (!clist)
        return -1;
    Node* head = clist->head;
    Node* cur = head;
    Node* prev = clist->tail;
    int index = 0;
    while (cur) {
        if (cur->data == data) {
            if (prev) {
                prev->next = cur->next;
            }
            if (cur == clist->head)
                clist->head = cur->next;
            if (cur == clist->tail)
                clist->tail = prev;
            clist->len--;
            free(cur);
            found = true;
            printf("Remove data %d at index %d\n", data, index);
            break;
        }
        prev = cur;
        cur = cur->next;
        if (cur == head)
            break;
        index++;
    }
    
    if (!found) {
        printf("ERR: remove failed as data %d is not in the list\n", data);
    }
    return ret;
}

int cll_length(cll* clist)
{
    if (!clist)
        return 0;
    printf("CLL length\t: %3d\n", clist->len);
    return clist->len;
}

void cll_print(cll* clist)
{
    if (!clist)
        return;
    Node* head = clist->head;
    if (NULL == head)
        return;
    
    Node* cur = head;
    printf("CLL Items\t: ");
    while (cur) {
        printf("%3d\t", cur->data);
        cur = cur->next;
        if (cur == head)
            break;
    }
    printf("\n");
}


int main(void)
{
    cll clist = {NULL, NULL, 0};
    
    cll_append(&clist, 60);
    cll_append(&clist, 70);
    cll_append(&clist, 80);
    cll_append(&clist, 90);
    cll_append(&clist, 100);

    
    cll_prepend(&clist, 50);
    cll_prepend(&clist, 40);
    cll_prepend(&clist, 30);
    cll_prepend(&clist, 20);
    cll_prepend(&clist, 10);

    
    cll_append(&clist, 110);
    cll_append(&clist, 120);
    
    cll_length(&clist);
    cll_print(&clist);
    
    cll_remove(&clist, 100);
    cll_length(&clist);
    cll_print(&clist);
    
    cll_remove(&clist, 10);
    cll_length(&clist);
    cll_print(&clist);

    cll_remove(&clist, 120);
    cll_length(&clist);
    cll_print(&clist);
    
    cll_remove(&clist, 200);
    cll_length(&clist);
    cll_print(&clist);
    return 0;
}