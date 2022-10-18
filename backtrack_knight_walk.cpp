#include <iostream>
#include <set>
#include <queue>
#include <climits>
using namespace std;

#define N 8

// Below arrays details all 8 possible movements
// for a knight
int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };

// Check if (x, y) is valid chess board coordinates
// Note that a knight cannot go out of the chessboard
bool valid(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N)
		return false;

	return true;
}


struct Node
{
	// (x, y) represents chess board coordinates
	// dist represent its minimum distance from the source
	int x, y, dist;

	// Node constructor
	Node(int x, int y, int dist = 0): x(x), y(y), dist(dist) {}

	bool operator<(const Node& o) const
	{
		return x < o.x || (x == o.x && y < o.y);
	}
};

// Find minimum number of steps taken by the knight
// from source to reach destination using BFS
int BFS(Node src, Node dest)
{
    queue<Node> q;
    q.push(src);
    bool visited[N][N] = {false};
    visited[src.x][src.y] = true;
    while(!q.empty()) {
        Node tmp = q.front();
        q.pop();
        if (tmp.x == dest.x && tmp.y == dest.y) {
            cout << "Found (" << dest.x << ", " << dest.y  << ") at distance of " << tmp.dist << endl;
            //return tmp.dist;
        }
        for (int i = 0; i < 8; i++) {
            int x = tmp.x+row[i];
            int y = tmp.y+col[i];
            int dist = tmp.dist+1;
            Node newNode(x,y,dist);
            if (valid(x,y) && !visited[x][y]) {
                q.push(newNode);
                visited[x][y] = true;
            }
        }
    }
	return 0;
}

int main()
{
	// source coordinates
	Node src = {0, 0};

	// destination coordinates
	Node dest = {2, 4};

	BFS(src, dest) ;

	return 0;
}