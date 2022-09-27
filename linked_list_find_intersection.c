#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Link list node */
typedef struct Node { 
    int data; 
    struct Node* next; 
}Node;

void print(Node* head)
{
    if (head == NULL)
        return NULL;
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int get_len(Node* head)
{
    int len = 0;
    while (head) {
        head = head->next;
        len++;
    }
    printf("list len %d\n", len);
    return len;
}

int findIntesectionNode(Node* head1, Node* head2) 
{
    if (head1 == NULL || head2 == NULL)
        return -1;
    int len1 = get_len(head1);
    int len2 = get_len(head2);
    
    Node* big = NULL;
    Node* small = NULL;
    int diff = 0;
    if (len1 > len2) {
        big = head1; small = head2;
        diff = len1-len2;
    } else {
        big = head2; small = head1;
        diff = len2-len1;
    }
    printf("diff %d big %d small %d", diff, big->data, small->data);
    while (diff) {
        big = big->next;
        diff--;
    }
    
    while (big != small) {
        big = big->next;
        small = small->next;
    }
    
    return big->data; 
} 
  
  
int main() 
{ 
    /*  
        Create two linked lists  
      
        1st 3->6->9->15->30  
        2nd 10->15->30  
      
        15 is the intersection point  
    */
  
    Node* newNode; 
  
    // Addition of new nodes 
    Node* head1 = calloc(1, sizeof(Node)); 
    head1->data = 10; 
  
    Node* head2 = calloc(1, sizeof(Node)); 
    head2->data = 3; 
  
    newNode = calloc(1, sizeof(Node)); 
    newNode->data = 6; 
    head2->next = newNode; 
  
    newNode = calloc(1, sizeof(Node)); 
    newNode->data = 9; 
    head2->next->next = newNode; 
  
    newNode = calloc(1, sizeof(Node));
    newNode->data = 15; 
    head1->next = newNode; 
    head2->next->next->next = newNode; 
  
    newNode = calloc(1, sizeof(Node)); 
    newNode->data = 30; 
    head1->next->next = newNode; 
  
    head1->next->next->next = NULL;
    print(head1);
    print(head2);
  
    printf("\nThe node of intersection is %d", findIntesectionNode(head1, head2)); 
} 

/*

    test_getIntersectionNode1():
      headA = ListNode(4)
      headB = ListNode(5)
      headA.next = ListNode(7)
      headA.next.next = ListNode(9)
      headB.next = ListNode(7)
    
      ob1 = new Main()
      actual = ob1.findIntersection(headA, headB)
      expected = 7
      

    test_getIntersectionNode2():
      headA = ListNode(4)
      headB = ListNode(5)
      headA.next = ListNode(7)
      headA.next.next = ListNode(9)
      headB.next = ListNode(17)
      headB.next.next = ListNode(18)
    
      ob1 = new Main()
      actual = ob1.findIntersection(headA, headB)
      expected = -1
     
*/