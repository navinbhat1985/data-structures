#include<bits/stdc++.h> 
using namespace std;

typedef struct Node {
    int key, value;
    struct Node* prev, *next;
} Node;

map<int, Node*> hash_map;
Node* head = NULL;
Node* tail = NULL;
#define MAX_CACHE_SIZE 3

Node* move_to_tail(Node* node)
{
    // move the Node to the tail
    if (node != tail) {
        if (node == head) {
            head = head->next;
        } else {
            node->prev->next  = node->next;
            node->next->prev = node->prev;
        }
        tail->next= node;
        node->prev = tail;
        tail = tail->next;
        tail->next= NULL;
    }
    return node;
}

int cache_get(int key)
{
    // Lookup the key in hash map
    map<int, Node*>::iterator it = hash_map.find(key);
    // if found,
    if (it != hash_map.end()) {
        // get the Node ptr 
        Node* node = it->second;
        // Move the NOde ptr to the tail
        move_to_tail(node);
        //  return the value of the Node
        return node->value;
    }
    return -1;
}

Node* append(int key, int value)
{
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->key = key; node->value = value;
    if (head == NULL) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = tail->next;
    }
    return node;
}

int cache_put(int key, int value)
{
    // check if key is present in the hash map
    map<int,Node*>::iterator it = hash_map.find(key);
    // if present,
    if (it != hash_map.end()) {
        // get the Node pointer
        Node* node= it->second;
        // Udate the value of the node ptr
        node->value = value;
        // move the Node to the tail
        move_to_tail(node);
    } else { // if not present,
        // check if hash map size < MAX_CACHE_SIZE
        if (hash_map.size() < MAX_CACHE_SIZE) {
            // if space is there,  then create a node and add to tail of dll
            Node* node = append(key,value); 
            // insert the key and Node ptr in to the hash map
            hash_map[key] = node;
        } else { // if space is not there
            // then get the head_ptr of DLL, save it
            // From the saved DLL head_ptr, lookup the key and delete it from hash_map to make space.
            map<int, Node*>::iterator it = hash_map.find(head->key);
            if (it != hash_map.end()) {
                hash_map.erase(it);
            }
            // remove the head from DLL
            Node* old_head = head;
            head = head->next;
            free(old_head);
            // Create a new node with the key-value and add it to tail of DLL
            Node* node = append(key,value); 
            // Add the key and Node ptr to the tail of DLL
            hash_map[key] = node;
        }
    }
    //return the value of new node
    return value;
}

void print_dll(Node* head)
{
    if (head == NULL)
        return;
    while (head) {
        printf("(%d-%d) -> ", head->key, head->value);
        head = head->next;
    }
    printf("NULL\n");
}


int main() 
{
    cache_put(1,1);
    cache_put(2,2);
    print_dll(head);
    cache_put(3,3);
    print_dll(head);
    cache_put(4,4);
    print_dll(head);
    cache_put(3,99);
    print_dll(head);
    cache_put(4,100);
    print_dll(head);
    cache_put(2,101);
    print_dll(head);
    cache_put(3,102);
    print_dll(head);
    
    printf("cache_get 4\n");
    cache_get(4);
    print_dll(head);
    printf("cache_get 3\n");
    cache_get(3);
    print_dll(head);
    printf("cache_get 4\n");
    cache_get(4);
    print_dll(head);
    cache_get(4);
    print_dll(head);
    
        
    return 0; 
}