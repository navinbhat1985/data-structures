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

Node* find_middle(Node* head)
{
    if (head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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

Node* reverse(Node* head)
{
    if (head == NULL)
        return NULL;
    Node* prev = NULL;
    Node* cur = head;
    Node* next = NULL;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
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
    
    Node* b = NULL;
    push(&b, 1); 
    push(&b, 2); 
    push(&b, 3); 
    push(&b, 4); 
    push(&b, 5);
    push(&b, 6);
    printf("\nLinked List b: "); 
    printList(b);
    
    Node* mid = find_middle(b);
    printf("\nmiddle node is %d", (mid) ? mid->data: -1);
    
    
    Node* c = reverse(b);
    printf("\nReversed Linked List b: "); 
    printList(c);
    
    return 0;
}
