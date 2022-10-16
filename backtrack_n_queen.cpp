#include <iostream>
#include <cstring>
using namespace std;
 
// N x N chessboard
#define N 8

bool isPositionSafe(char mat[][N], int r, int c)
{
    int rdu, rdd, rl;
    rdu = rdd = r;
    while (--c >= 0) {
        // check if there is queen on the left of row
        if (mat[r][c] == 'Q')
            return false;
        // check if there is queen on left diagonal upwards
        if (mat[--rdu][c] == 'Q')
            return false;
        // check if there is queen on left diagonal downwards
        if (mat[++rdd][c] == 'Q')
            return false;
    }
    return true;
}


bool nQueen(char mat[][N], int c)
{
    if (c >= N) {
        return true;
    }
    for (int r = 0 ; r < N; r++) {
        if (isPositionSafe(mat, r,c)) {
            mat[r][c] = 'Q';
            if (nQueen(mat, c+1))
                return true;
            mat[r][c] = '-';
        }
    }
    return false;
}
 
int main()
{
    // mat[][] keeps track of position of Queens in current configuration
    char mat[N][N];
 
    // initialize mat[][] by '-'
    memset(mat, '-', sizeof mat);
 
    nQueen(mat, 0);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
 
    return 0;
}