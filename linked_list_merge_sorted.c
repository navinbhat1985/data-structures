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

Node* merge_lists(Node* a, Node* b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    Node* prev = NULL;
    Node* cur1 = a;
    Node* cur2 = b;

    while (cur1 && cur2) {
        if (cur1->data >= cur2->data) {
            if (prev == NULL) {
                a = prev = cur2;
                cur2 = cur2->next;
                prev->next = cur1;
            } else {
                prev->next = cur2;
                prev = prev->next;
                cur2 = cur2->next;
                prev->next = cur1;
            }
        } else {
            prev = cur1;
            cur1 = cur1->next;
        }
    }
    
    if (cur2) {
        prev->next = cur2;
    }
    return a;
}


int main() 
{ 
    /* Start with the empty list */
    Node* a = NULL; 
    Node* b = NULL; 
  
    push(&a, 150); 
    push(&a, 130); 
    push(&a, 110); 
    push(&a, 90); 
    push(&a, 70); 
    push(&a, 50);
    push(&a, 30);
    push(&a, 10);
  
    printf("\nSorted Linked List 1: "); 
    printList(a);
    
    push(&b, 160); 
    push(&b, 140); 
    push(&b, 120); 
    push(&b, 100); 
    push(&b, 80); 
    push(&b, 60);
    push(&b, 40);
    push(&b, 20);
  
    printf("\nSorted Linked List 2: "); 
    printList(b);
  
    printf("\nMerged Linked List: ");
    Node *c = merge_lists(a, b);
    printList(c);
    return 0;
}

/* Try more Inputs
Case 1:
Node* res = NULL; 
Node* a = NULL;
push(&a, 3); 
push(&a, 2); 
push(&a, 1);
MergeSort(&a); 
printList(a,array);
expected = [1,2,3]

Case 2:
Node* res = NULL; 
Node* a = NULL;
push(&a, 1);
MergeSort(&a); 
printList(a,array);
expected = [1]
*/