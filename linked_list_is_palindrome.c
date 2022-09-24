#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Link list node */
typedef struct Node { 
    int data; 
    struct Node* next; 
}Node; 
  
/* Function to print nodes in a given linked list */
void printList(Node* node) 
{ 
    if (node == NULL)
        return;
    while (node) {
        printf(" %d ", node->data);
        node = node->next;
    }
    printf("\n");
} 
  
/* Function to insert a node at the beginging of the linked list */
void push(Node** head_ptr, int new_data) 
{
    if (head_ptr == NULL)
        return;
    Node* head = *head_ptr;
    Node* node = calloc(1, sizeof(Node));
    node->data = new_data;
    node->next = head;
    head = node;
    *head_ptr = head;
    return;
} 

bool is_palindrome(Node** head_ptr, Node* node)
{
    if (head_ptr == NULL || *head_ptr == NULL)
        return true;
    if (node == NULL)
        return true;
    printf("head %d node %d\n", (*head_ptr)->data, node->data);
    if (is_palindrome(head_ptr, node->next)) {
        Node* head = *head_ptr;
        printf("Compare head %d node %d\n", (*head_ptr)->data, node->data);
        if (head->data == node->data) {
            *head_ptr = head->next;
            return true;
        }
    }
    return false;
}

int main() 
{ 
    /* Start with the empty list */
    Node* a = NULL; 
  /*
    push(&a, 1); 
    push(&a, 2); 
    push(&a, 3); 
    push(&a, 4); 
    push(&a, 3); 
    push(&a, 2);
    push(&a, 1);
  */
    push(&a, 1); 
    push(&a, 2); 
    push(&a, 3); 
    push(&a, 3); 
    push(&a, 2);
    push(&a, 1);
    
    printf("\nLinked List 1: "); 
    printList(a);
    Node* list = a;
    
    if (is_palindrome(&list, a)) {
        printf("\nList is palindrome");
    } else {
        printf("\nList is not a palindrome");
    }
    return 0;
}
