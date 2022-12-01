//g++  7.4.0

#include <iostream>
#include <map>
#include <list>
using namespace std;

void add_edge(int i, int j, map<int, list<int>> &hmap)
{
    hmap[i].push_back(j);
}

void print_adj_matrix(map<int, list<int>> &hmap)
{
    map<int, list<int>>::iterator it = hmap.begin();
    while(it != hmap.end()) {
        cout << it->first << " -> ";
        list<int>::iterator it1 = it->second.begin();
        while(it1 != it->second.end()) {
            cout << *it1 << " -> ";
            it1++;
        }
        cout << endl;
        it++;
    }
}

int main()
{
    map<int, list<int>> hmap;
    int vertices = 6;
    add_edge(0, 1, hmap);
    add_edge(0, 2, hmap);
    add_edge(0, 2, hmap);
    add_edge(1, 0, hmap);
    add_edge(1, 3, hmap);
    add_edge(1, 4, hmap);
    add_edge(2, 0, hmap);
    add_edge(3, 1, hmap);
    add_edge(3, 5, hmap);
    add_edge(4, 1, hmap);
    add_edge(4, 5, hmap);
    add_edge(5, 3, hmap);
    add_edge(5, 4, hmap);
    print_adj_matrix(hmap);
}

