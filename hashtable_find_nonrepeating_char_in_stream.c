//gcc 7.4.0

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    char ch;
    struct Node* next, *prev;
}Node;


Node* append(Node** head_ptr, Node** tail_ptr, char ch)
{
    if (head_ptr == NULL || tail_ptr == NULL) 
        return NULL;
    Node* head = *head_ptr;
    Node* tail = *tail_ptr;
    Node* node = calloc(1, sizeof(Node));
    node->ch = ch;
    if (head == NULL)  {
        head = tail = node;
    } else {
        node->prev = tail;
        tail->next = node;
        tail = tail->next;
    }
    *head_ptr = head;
    *tail_ptr = tail;
    return node;
}

void remove_node(Node** head_ptr, Node** tail_ptr, Node* tmp)
{
    if (head_ptr == NULL || tail_ptr == NULL)
        return;
    Node* head = *head_ptr;
    Node* tail = *tail_ptr;
    if (head == tmp) {
        head = head->next;
        head->prev = NULL;
        free(tmp);
    } else if (tail == tmp) {
        tail = tail->prev;
        tail->next = NULL;
        free(tmp);
    } else {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        free(tmp);
    }
    *head_ptr = head;
    *tail_ptr = tail;
}

void print_dll(Node* head)
{
    if (head == NULL)
        return;
    while(head) {
        printf("%d -> ", head->ch);
        head = head->next;
    }
    printf("\n");
}

void find_nonrepeating(char* stream)
{
    if (stream == NULL)
        return;
    Node* ascii_nodes[256] = { NULL };
    bool repeated[256] = {false};
    int len = strlen(stream);
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < len; i++) {
        if (!repeated[stream[i]]) {
            // append the char node to the dll
            if (ascii_nodes[stream[i]] == NULL) {
                ascii_nodes[stream[i]] = append(&head, &tail, stream[i]);
            } else {
                repeated[stream[i]] = true;
                // remove the node from the dll
                Node* tmp = ascii_nodes[stream[i]];
                ascii_nodes[stream[i]] = NULL;
                remove_node(&head, &tail, tmp);
            }
        }
        printf ("first non repeating char is %c\n", (head) ? head->ch : '-');
        print_dll(head);
    }
    
}

int main(void)
{
    
    char stream[] = "ABCDBAGHC";
    find_nonrepeating(stream);
    return 0;
}