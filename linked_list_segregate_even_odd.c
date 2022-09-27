#include <stdio.h>  
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{  
    int data;  
    struct Node *next;  
}Node;  

/*
void segregateEvenOdd(Node **head_ptr)  
{
    if (head_ptr == NULL || *head_ptr == NULL)
        return;
    Node* head = *head_ptr;
    Node* odd = head;
    Node* prev = head;
    Node* cur = head->next;
    while (cur && odd) {
        if (odd->data % 2 != 0) {
            if (cur->data %2 == 0) {
                // swap even and odd nodes
                int tmp = odd->data;
                odd->data = cur->data;
                cur->data = tmp;
                odd = odd->next;
            }
        } else {
            odd = odd->next;
        }
        cur = cur->next;
    }
    return;  
}  
 */

void segregateEvenOdd(Node **head_ptr)  
{
    if (head_ptr == NULL || *head_ptr == NULL)
        return;
    Node* head = *head_ptr;
    Node* odd_head = NULL;
    Node* odd_tail = NULL;
    Node* even_head = NULL;
    Node* even_tail = NULL;
    Node* cur = head;
    Node* next = NULL;
    while (cur) {
        next = cur->next;
        if ((cur->data % 2) == 0) {
            if (even_head == NULL) {
                even_head = even_tail = cur;
                even_tail->next = NULL;
            } else {
                even_tail->next = cur;
                even_tail = cur;
                even_tail->next = NULL;
            }
        } else {
            if (odd_head == NULL) {
                odd_head = odd_tail = cur;
                odd_tail->next = NULL;
            } else {
                odd_tail->next = cur;
                odd_tail = cur;
                odd_tail->next = NULL;
            }
        }
        cur = next;
    }
    if (even_head) {
        *head_ptr = even_head;
        even_tail->next = odd_head;
    } else {
        *head_ptr = odd_head;
    }
}

/* Function to insert a node at the beginning */
void insert(Node** head, int new_data)  
{  
    /* allocate node */
    Node* new_node = calloc(1, sizeof(Node)); 
  
    /* put in the data */
    new_node->data = new_data;  
  
    /* link the old list off the new node */
    new_node->next = (*head);  
  
    /* move the head to point to the new node */
    (*head) = new_node;  
}  
  
/* Function to print nodes in a given linked list */
void printList(Node *node)  
{  
    while (node != NULL) {  
        printf( "%d -> ", node->data);  
        node = node->next;  
    }
    printf("NULL\n");
}
  
int main()  
{  
    /* Start with the empty list */
    Node* head = NULL;  
  
    /* Let us create a sample linked list as following  
    0->2->4->6->8->10->11 */
  
    insert(&head, 7);  
    insert(&head, 3);  
    insert(&head, 8);  
    insert(&head, 6);
    insert(&head, 4);  
    insert(&head, 5);  
    insert(&head, 2);  
  
    printf("Original Linked list :");  
    printList(head);  
  
    segregateEvenOdd(&head);  

    printf("\nModified Linked list: ");  
    printList(head);  
  
    return 0;  
}  
