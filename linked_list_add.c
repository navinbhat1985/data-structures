#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node  
{  
    int data;  
    struct Node* next;  
}Node ;  
  
void insert(Node** head_ref, int new_data)  
{  
    Node* new_node = calloc(1, sizeof(Node));
    new_node->data = new_data;  
    new_node->next = (*head_ref);  
    (*head_ref) = new_node;  
}  

void printList(Node *node)  
{  
    while (node != NULL) {  
        printf("%d -> ", node->data);  
        node = node->next;  
    }
    printf("NULL\n");
}
/*
int addLinkedList(Node* head1, Node* head2, Node** result)  
{
    if (head1 == NULL && head2 == NULL)
        return 0;
    
    if (head1->next == NULL && head2->next == NULL) {
        return (head1->data + head2->data)
    }
    
    Node* list1 = (head1->next != NULL) ? head1->next : head1;
    Node* list2 = (head2->next != NULL) ? head2->next : head2;
    
    int sum = addLinkedList(list1, list2, result);
    int carry = 0;
    if (sum > 10) {
        carry = sum/10
        sum = sum % 10;
    }
    printf("Insert %d in result list\n", sum);
    insert(result, sum);
    return carry;
}  
*/

int get_num(Node* head)
{
    if (head == NULL)
        return 0;
    int num = 0;
    Node* cur = head;
    while (cur) {
        num = num*10 + cur->data;
        cur = cur->next;
    }
    printf("num = %d\n", num);
    return num;
}

void addLinkedList(Node* head1, Node* head2, Node** result)  
{
    if (head1 == NULL && head2 == NULL)
        return 0;
    int sum = get_num(head1) + get_num(head2);
    printf("sum %d\n", sum);
    while (sum) {
        int data = sum % 10;
        sum = sum/10;
        insert(result, data);
    }
    return ;
}  
  
  
int main()  
{  
    Node *head1 = NULL, *head2 = NULL, *result = NULL;  
  
    int arr1[] = {9, 9, 9};  
    int arr2[] = {1, 8};  
  
    int size1 = sizeof(arr1) / sizeof(arr1[0]);  
    int size2 = sizeof(arr2) / sizeof(arr2[0]);  
  
    // Create first list as 9->9->9  
    int i;  
    for (i = size1-1; i >= 0; --i)  
        insert(&head1, arr1[i]);  
  
    // Create second list as 1->8  
    for (i = size2-1; i >= 0; --i)  
        insert(&head2, arr2[i]);  
  
    addLinkedList(head1, head2, &result);  
  
    printf("\nList 1: ");
    printList(head1);
    printf("\nList 2: ");
    printList(head2);
    printf("\nResult List: ");
    printList(result);  
  
    return 0;  
}