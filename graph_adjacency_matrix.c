//gcc 7.4.0

#include  <stdio.h>

int main(void)
{
    int num_vertex = 5;
    int adj_matrix[num_vertex][num_vertex];
    memset(adj_matrix, 0, sizeof(int) * num_vertex * num_vertex);
    adj_matrix[0][1] = adj_matrix[0][4] = 1;
    adj_matrix[1][0] = adj_matrix[1][2] = adj_matrix[1][3] = adj_matrix[0][4] = 1;
    adj_matrix[2][1] = adj_matrix[2][3] = 1;
    adj_matrix[3][1] = adj_matrix[3][2] = adj_matrix[3][4] = 1;
    adj_matrix[4][0] = adj_matrix[4][1] = adj_matrix[4][3] = 1;
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < num_vertex; i++) {
        printf("%d--> ", i);
        for (int j = 0; j < num_vertex; j++) {
            if (adj_matrix[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    return 0;
}