#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


// Function to generate power set of given set S
void findPowerSet(vector<int> const &S, vector<int> &set, int sz, int start)
{
    if (set.size() == sz) {
        for(int i = 0; i < set.size(); i++) {
            cout << " " << set[i] ;
        }
        cout << endl;
        return;
    }
    
    for (int i = start; i < S.size(); i++) {
        set.push_back(S[i]);
        findPowerSet(S, set, sz, i+1);
        set.pop_back();
    }
    
}

int main()
{
	vector<int> S = { 1, 2, 3 };
	int n = S.size();
	vector<int> set;

    for (int i = 0; i < n; i++) {
        findPowerSet(S, set, i+1, 0);
    }

	return 0;
}