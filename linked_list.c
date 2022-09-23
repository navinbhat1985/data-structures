//gcc 7.4.0

#include  <stdio.h>
#include  <stdlib.h>
#include  <stdbool.h>


typedef struct  Node{
    int data;
    struct Node *next;
}Node;

typedef struct linked_list {
    Node* head;
    Node* tail;
    unsigned int len;
}linked_list;

Node* ll_append(linked_list *ll, int data)
{
    Node* node = calloc(1, sizeof(Node));
    node->data = data;
    if (ll->head == NULL) {
        ll->head = ll->tail = node;
    } else {
        ll->tail->next = node;
        ll->tail = node;
    }
    ll->len++;
    return node;
}

Node* ll_prepend(linked_list *ll, int data)
{
    Node* node = calloc(1, sizeof(Node));
    node->data = data;
    if (ll->head == NULL) {
        ll->head = ll->tail = node;
    } else {
        node->next = ll->head;
        ll->head = node;
    }
    ll->len++;
    return node;
}

bool ll_find(linked_list* ll, int data)
{
    Node* cur = ll->head;
    int index = 0;
    while (cur) {
        if (cur->data == data) {
            printf("found %d in linked list at index %d\n", data, index);
            return true;
        }
        cur = cur->next;
        index++;
    }
    printf("%d is not found in linked list\n", data);
    return false;
}

bool ll_delete(linked_list* ll, int data)
{
    Node* prev = NULL;
    Node* cur = ll->head;
    while (cur) {
        if (cur->data == data) {
            if(prev != NULL) {
                prev->next = cur->next;
            }
            if (ll->head == cur)
                ll->head = cur->next;
            if (ll->tail == cur)
                ll->tail = prev;
            free(cur);
            ll->len--;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

void ll_print(linked_list* ll)
{
    Node* cur = ll->head;
    printf("Linked list has %d nodes : ", ll->len);
    while (cur) {
        printf("%d -> ", cur->data);
        cur =  cur->next;
    }
    printf("NULL\n");
}

int main(void)
{
    linked_list ll = {0};
    ll_append(&ll, 10);
    ll_append(&ll, 20);
    ll_append(&ll, 30);
    ll_append(&ll, 40);
    ll_append(&ll, 50);
    ll_append(&ll, 60);
    ll_append(&ll, 70);
    ll_append(&ll, 80);
    ll_print(&ll);
    
    
    ll_prepend(&ll, 90);
    ll_prepend(&ll, 100);
    ll_prepend(&ll, 110);
    ll_prepend(&ll, 120);
    ll_prepend(&ll, 130);
    ll_prepend(&ll, 140);
    ll_prepend(&ll, 150);
    ll_prepend(&ll, 160);
    ll_print(&ll);
    
    ll_delete(&ll, 160);
    ll_print(&ll);
    ll_delete(&ll, 80);
    ll_print(&ll);
    ll_delete(&ll, 90);
    ll_print(&ll);
    
    ll_find(&ll, 20);
    ll_find(&ll, 200);
    return 0;
    
}