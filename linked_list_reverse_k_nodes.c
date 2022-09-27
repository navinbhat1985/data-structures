#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Link list node */
typedef struct Node  
{  
    int data;  
    struct Node* next;  
}Node;  
  
/* Reverses the linked list in groups 
of size k and returns the pointer 
to the new head node. */
Node *reverse (Node *head, int k)  
{
    if (head == NULL)
        return NULL;
    
    Node* cur = head;
    Node* prev = NULL;
    Node* next = NULL;
    Node* prev_tail = prev;
    bool once = true;
    while (cur && k > 0) {
        int count = k;
        Node* tail = cur;
        while (cur && count--) {
            next = cur->next;
            cur->next= prev;
            prev = cur;
            cur = next;
        }
        if (once) {
            head = prev;
            once = false;
        }
        if (tail)
            tail->next = cur;
        if (prev_tail)
            prev_tail->next = prev;
        prev_tail = tail;
    }
    return head;
}  

/* Function to Insert a node */
void insert(Node** head, int new_data)  
{  
    Node* new_node = calloc(1, sizeof(Node)); 
    new_node->data = new_data;  
    new_node->next = (*head);      
    (*head) = new_node;  
}  
  
/* Function to print linked list */
void printList(Node *node)  
{  
    while (node != NULL) {  
        printf("%d -> ", node->data);  
        node = node->next;  
    }
    printf("NULL\n");
}  
  
int main()  
{  
    /* Start with the empty list */
    Node* head = NULL;  
  
    /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
    insert(&head, 9);  
    insert(&head, 8);  
    insert(&head, 7);  
    insert(&head, 6);  
    insert(&head, 5);  
    insert(&head, 4);  
    insert(&head, 3);  
    insert(&head, 2);  
    insert(&head, 1);      
  
    printf("\nGiven linked list :");  
    printList(head);  
    head = reverse(head, 2);  
  
    printf("\nReversed Linked list :");  
    printList(head);  
  
    return(0);  
}  
