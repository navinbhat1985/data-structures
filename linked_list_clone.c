#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Structure of linked list Node 
typedef struct Node 
{ 
    int data; 
    struct Node *next,*random; 
}Node; 

Node* newNode(int data)
{
    Node* node = calloc(1, sizeof(Node));
    node->data = data;
    return node;
}
  
// Utility function to print the list. 
void print(Node *start) 
{ 
    Node* cur = start;
    while (cur) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void print_random(Node *start) 
{ 
    Node* cur = start;
    while (cur) {
        printf("(%d -> %d) ", cur->data, cur->random->data);
        cur = cur->next;
    }
    printf("NULL\n");
}
  
// This function clones a given linked list 
Node* clone(Node *start) 
{ 
    if (start == NULL)
        return NULL;
    Node* cur = start;
    Node* new = calloc(1, sizeof(Node));
    new->data = start->data;
    Node* tmp = new;
    cur = start->next;
    while (cur) {
        tmp->next = calloc(1, sizeof(Node));
        tmp->next->data = cur->data;
        cur = cur->next;
        tmp = tmp->next;
    }
    
    Node* first = start;
    Node* second = new;
    
    while (first) {
        Node* tmp = first->next;
        first->next = second;
        second->random = first;
        first = tmp;
        second = second->next;
    }
    
    first = start;
    second = new;
    
    while (second) {
        second->random = second->random->random->next;
        second = second->next;
    }
    
    return new;
} 
  
// Driver code 
int main() 
{ 
    Node* start = newNode(2); 
    start->next = newNode(4); 
    start->next->next = newNode(5); 
    start->next->next->next = newNode(6); 
    start->next->next->next->next = newNode(7); 
  
    // 3's random points to 5 
    start->random = start->next->next; 
  
    // 4's random points to 2 
    start->next->random = start; 
  
    // 5's and 6's random points to 7 
    start->next->next->random = 
                    start->next->next->next->next; 
    start->next->next->next->random = 
                    start->next->next->next->next; 
  
    // 7's random points to 4 
    start->next->next->next->next->random = 
                                      start->next; 
  
    printf("Original list : \n"); 
    print(start); 
    print_random(start);
  
    printf("\nCloned list : \n"); 
    Node *cloned_list = clone(start); 
    print(cloned_list);
    print_random(cloned_list);
  
    return 0; 
} 
