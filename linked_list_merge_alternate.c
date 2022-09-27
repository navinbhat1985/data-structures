#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Link list node */
typedef struct Node  
{  
    int data;  
    struct Node* next;  
}Node;  

/* Function to print linked list */
void printList(Node *node)  
{  
    while (node != NULL) {  
        printf("%d -> ", node->data);  
        node = node->next;  
    }
    printf("NULL\n");
}  

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

Node* swap_ends(Node* head, Node* tail_prev, Node* tail)
{
    if (head == NULL)
        return NULL;
    if (tail == NULL)
        return head;
    if (head == tail)
        return NULL;
    
    Node* head_ptr = swap_ends(head, tail, tail->next);
    Node* next = NULL; 
    if (head_ptr && head_ptr != tail && head_ptr->next != tail) {
        printf("head_ptr %d tail_prev %d tail %d\n", (head_ptr) ? head_ptr->data: -1, tail_prev->data, tail->data);
        next = head_ptr->next;
        head_ptr->next = tail;
        tail->next = next;
        tail_prev->next = NULL;
    }
    return next;
}

Node* get_middle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* reverse_list(Node* head)
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

Node* merge_alternate(Node* head1, Node* head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    Node* cur1 = head1;
    Node* cur2 = head2;
    while(cur1 && cur2) {
        Node* next1 = cur1->next;
        cur1->next = cur2;
        Node* next2 = cur2->next;
        cur1 = next1;
        cur2->next = cur1;
        cur2 = next2;
    }
    
    if (cur2)
        cur1->next = cur2;
    
    return head1;
}

Node* rearrange_list(Node* head)
{
    if (head == NULL)
        return NULL;
    // find middle
    Node* mid = get_middle(head);
    Node* mid_next = mid->next;
    printList(mid_next);
    mid->next = NULL;
    // reverse the middle list
    mid_next = reverse_list(mid_next);
    printList(head);
    printList(mid_next);
    // merge the lists
    Node* result = merge_alternate(head, mid_next);
    return result;
}

/* Function to Insert a node */
void insert(Node** head, int new_data)  
{  
    Node* new_node = calloc(1, sizeof(Node)); 
    new_node->data = new_data;  
    new_node->next = (*head);      
    (*head) = new_node;  
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
    //head = reverse(head, 2);
    //swap_ends(head, head, head->next);
     rearrange_list(head);
    printf("\nReversed Linked list :");  
    printList(head);  
  
    return(0);  
}  