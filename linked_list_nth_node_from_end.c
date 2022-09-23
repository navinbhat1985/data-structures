#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
  
/* Link list node */
typedef struct Node { 
    int data; 
    struct Node* next; 
}Node; 
  
/* Function to get the nth node from the last of a linked list*/
void printNthFromLast(struct Node* head, int n) 
{
    Node* end = head;
    int count = n-1;
    while (count && end) {
        end = end->next;
        count--;
    }
    if (end == NULL) {
        printf("There is no element at %dth position\n", n);
        return;
    }
    Node* start = head;
    while (end->next) {
        start = start->next;
        end = end->next;
    }
    
    printf("%dth node from end is %d", n, start->data);
    return; 
} 
  
void insert(struct Node** head_ptr, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node = calloc(1, sizeof(Node)); 
  
    /* put in the data */
    new_node->data = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ptr); 
  
    /* move the head to point to the new node */
    (*head_ptr) = new_node; 
} 
  

int main() 
{ 
 
    struct Node* head = NULL; 
  
    // create linked 35->15->4->20 
    insert(&head, 20); 
    insert(&head, 4); 
    insert(&head, 15); 
    insert(&head, 35); 
  
    printNthFromLast(head, 4); 
    return 0; 
}