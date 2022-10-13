#include<stdio.h>
#include<stdbool.h>

#define N 5

int maze[N][N]  =  {
   {1, 0, 0, 0, 0},
   {1, 1, 0, 1, 0},
   {0, 1, 1, 1, 0},
   {0, 0, 0, 1, 0},
   {1, 1, 1, 1, 1}
};

int sol[N][N] = {0};         //final solution of the maze path is stored here

void print_mat(int mat[][N], int sz)
{
    printf("\n");
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

bool is_valid_path(int mat[][N], int x, int y)
{
    return (x < N && y < N && mat[x][y] ==1);
}

bool findSolution(int mat[][N], int x, int y, int path[][N]) 
{
    if (x == N-1 && y == N-1) {
        path[x][y] = 1;
        return true;
    }
    if (is_valid_path(mat, x, y)) {
        path[x][y] = 1;
        if (findSolution(mat, x+1, y, path))
            return true;
        if (findSolution(mat, x, y+1, path))
            return true;
        path[x][y] = 0;
        return false;
    }
    return false;
}

int main() {
    print_mat(maze, N);
    findSolution(maze, 0, 0, sol);
    print_mat(sol, N);
}
