#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

void print(Node* head)
{
    if (head == NULL)
        return;
    Node* cur = head;
    while (cur) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

Node* get_middle(Node* head)
{
    if (head == NULL)
        return NULL;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* l1, Node* l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    
    Node* prev = NULL;
    Node* cur1 = l1;
    Node* cur2 = l2;
    
    while (cur1 && cur2) {
        if (cur1->data >= cur2->data) {
            if (prev == NULL) {
                l1 = prev = cur2;
                cur2 = cur2->next;
                prev->next = cur1;
            } else {
                prev->next = cur2;
                prev = cur2;
                cur2 = cur2->next;
                prev->next = cur1;
            }
        } else {
            prev = cur1;
            cur1 = cur1->next;
        }
    }
    
    if (cur2) {
        if (prev)
            prev->next = cur2;
    }
    return l1;
}

Node* merge_sort(Node* head)
{
   if (head == NULL || head->next == NULL)
       return head;
    Node* mid = get_middle(head);
    Node* mid_next =  NULL;
    if (mid) {
        printf("\nmid element is %d", mid->data);
        mid_next = mid->next;
        mid->next = NULL;
    }
    
    Node* first = merge_sort(head);
    Node* second = merge_sort(mid_next);
    
    Node* sorted = merge(first, second);
    return sorted;
}


Node* append(Node* head, int data)
{
    Node* node = calloc(1, sizeof(Node));
    node->data = data;
    if (head == NULL) {
        return node;
    }
    Node* cur = head;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = node;
    return head;
}

int main()
{
    Node* head = NULL;
    head = append(head, 30);
    append(head, 10);
    append(head, 50);
    append(head, 20);
    append(head, 70);
    append(head, 40);
    append(head, 60);
    printf("\nUnsorted list :");
    print(head);
    
    Node* mid = get_middle(head);
    printf("\nmid node is %d", (mid) ? mid->data : -1);
    
    Node* sorted = merge_sort(head);
    printf("\nSorted list :");
    print(sorted);
}