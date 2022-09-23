//gcc 7.4.0

#include  <stdio.h>
#include  <stdlib.h>
#include  <stdbool.h>


typedef struct  Node{
    int data;
    struct Node *next, *prev;
}Node;

typedef struct doubly_linked_list {
    Node* head;
    Node* tail;
    unsigned int len;
}doubly_linked_list;

Node* dll_append(doubly_linked_list *dll, int data)
{
    Node* node = calloc(1, sizeof(Node));
    node->data = data;
    if (dll->head == NULL) {
        dll->head = dll->tail = node;
    } else {
        dll->tail->next = node;
        node->prev = dll->tail;
        dll->tail = node;
    }
    dll->len++;
    return node;
}

Node* dll_prepend(doubly_linked_list *dll, int data)
{
    Node* node = calloc(1, sizeof(Node));
    node->data = data;
    if (dll->head == NULL) {
        dll->head = dll->tail = node;
    } else {
        node->next = dll->head;
        dll->head->prev = node;
        dll->head = node;
    }
    dll->len++;
    return node;
}

bool dll_find(doubly_linked_list* dll, int data)
{
    Node* cur = dll->head;
    int index = 0;
    while (cur) {
        if (cur->data == data) {
            printf("found %d in doubly linked list at index %d\n", data, index);
            return true;
        }
        cur = cur->next;
        index++;
    }
    printf("%d is not found in doubly linked list\n", data);
    return false;
}

bool dll_delete(doubly_linked_list* dll, int data)
{
    Node* prev = NULL;
    Node* cur = dll->head;
    Node* next = NULL;
    while (cur) {
        next = cur->next;
        if (cur->data == data) {
            if(prev != NULL) {
                prev->next = cur->next;
            }
            if (next != NULL) {
                next->prev = prev;
            }
            if (dll->head == cur) {
                dll->head = next;
            }
            if (dll->tail == cur) {
                dll->tail = prev;
            }
            free(cur);
            dll->len--;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

void dll_print(doubly_linked_list* dll)
{
    Node* cur = dll->head;
    printf("Doubly Linked list has %d nodes : ", dll->len);
    while (cur) {
        printf("%d -> ", cur->data);
        cur =  cur->next;
    }
    printf("NULL\n");
}

void dll_print_reverse(doubly_linked_list* dll)
{
    Node* cur = dll->tail;
    printf("Doubly Linked list has %d nodes : ", dll->len);
    while (cur) {
        printf("%d <- ", cur->data);
        cur =  cur->prev;
    }
    printf("NULL\n");
}


int main(void)
{
    doubly_linked_list dll = {0};
    dll_append(&dll, 10);
    dll_append(&dll, 20);
    dll_append(&dll, 30);
    dll_append(&dll, 40);
    dll_append(&dll, 50);
    dll_append(&dll, 60);
    dll_append(&dll, 70);
    dll_append(&dll, 80);
    dll_print(&dll);
    dll_print_reverse(&dll);
    
    
    dll_prepend(&dll, 90);
    dll_prepend(&dll, 100);
    dll_prepend(&dll, 110);
    dll_prepend(&dll, 120);
    dll_prepend(&dll, 130);
    dll_prepend(&dll, 140);
    dll_prepend(&dll, 150);
    dll_prepend(&dll, 160);
    dll_print(&dll);
    dll_print_reverse(&dll);
    
    dll_delete(&dll, 160);
    dll_print(&dll);
    dll_print_reverse(&dll);
    dll_delete(&dll, 80);
    dll_print(&dll);
    dll_print_reverse(&dll);
    dll_delete(&dll, 90);
    dll_print(&dll);
    dll_print_reverse(&dll);
    
    
    dll_find(&dll, 20);
    dll_find(&dll, 200);
    return 0;
}