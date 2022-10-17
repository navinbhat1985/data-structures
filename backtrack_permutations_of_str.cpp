#include <iostream>
using namespace std;


void swap(string &str, int src, int dst)
{
    cout << "swap " << src << " "  << dst << " "<< str[src] << " with " << str[dst] ; 
    char tmp = str[src];
    str[src] = str[dst];
    str[dst] = tmp;
    cout << "(" << str << ")" << endl;
}
// Function to find all Permutations of a given string str[i..n-1]
// containing all distinct characters
void permutations(string str, int start, int end)
{
    if (start >= end) {
        cout << str << endl;
    } else {
        for (int index = start; index < end; index++) {
            swap(str, start, index);
            permutations(str, (start+1) , end);
            swap(str, start, index);
        }
    }
}


int main()
{
    string str = "ABC";

    permutations(str, 0, str.length());

    return 0;
}
