#include  <stdio.h>
#include  <stdlib.h>
#include  <stdbool.h>

typedef struct adj_node {
    int value;
    struct adj_node* next;
} adj_node;

typedef struct graph {
    int num_vertex;
    adj_node** adj_list;
} graph;

graph* create_graph(int num_vertex)
{
    if (0 == num_vertex)
        return NULL;
    graph* g = calloc(1, sizeof(graph));
    g->num_vertex = num_vertex;
    g->adj_list = calloc(num_vertex, sizeof(adj_node*));
    return g;
}

adj_node* add_vertex(graph* g, int value)
{
    if (!g)
        return NULL;
    bool created = false;
    adj_node* node = NULL;
    for (int i = 0; i < g->num_vertex; i++) {
        if (g->adj_list[i] == NULL) {
            node = calloc(1, sizeof(adj_node));
            node->value = value;
            g->adj_list[i] = node;
            created = true;
            break;
        }
    }
    if (!created) {
        printf("\n graph full: failed to add vertex %d, max vertices %d\n", value, g->num_vertex);
        return NULL;
    }
    printf("\n Added %d vertex to the graph\n", value);
    return node;
}

adj_node* get_adj_list(graph *g, int src)
{
    if (!g)
        return NULL;
    adj_node* head = NULL;
    for (int i = 0; i < g->num_vertex; i++) {
        if (g->adj_list[i]) {
            if (g->adj_list[i]->value == src) {
                head = g->adj_list[i];
                break;
            }
        }
    }
    return head;
}

int add_edge(graph *g, int src, int dst)
{
    if (!g)
        return -1;
    
    adj_node* head = get_adj_list(g, src);
    if (!head) {
        head = add_vertex(g, src);
    }
    // add the src->dst edge in adj list
    adj_node* cur = head;
    while (cur) {
        if (cur->next == NULL) {
            adj_node *node = calloc(1, sizeof(adj_node));
            node->value = dst;
            node->next = NULL;
            cur->next = node;
            printf("Edge %d --> %d, ", src, dst);
            break;
        }
        cur = cur->next;
    }
    // un-directed graph add an edge from dst->src
    head = get_adj_list(g, dst);
    if (!head) {
        head = add_vertex(g, dst);
    }
    // add the dst->src edge in adj list
    cur = head;
    while (cur) {
        if (cur->next == NULL) {
            adj_node *node = calloc(1, sizeof(adj_node));
            node->value = src;
            node->next = NULL;
            cur->next = node;
            printf("Edge %d --> %d, ", dst, src);
            break;
        }
        cur = cur->next;
    }
    printf("\n");
    return 0;
}

void print_graph(graph *g)
{
    if (!g)
        return;
    printf("\n Num Vertex : %d\n", g->num_vertex);
    for (int i = 0; i < g->num_vertex; i++) {
        if (g->adj_list[i]) {
            printf("vertex %d edges: ", g->adj_list[i]->value);
            adj_node* cur = g->adj_list[i];
            // print the adj list per vertex
            while (cur) {
                printf("-->%d ", cur->value);
                cur = cur->next;
            }
        }
        printf("\n");
    }
}

int main(void)
{
    struct graph* g = create_graph(5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 4);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
 
    // print the adjacency list representation of the above
    // graph
    print_graph(g);
    return 0;
}