#include <iostream>
#include <vector>
using namespace std;

void printCombination(vector<vector<int>> const &out)
{
    for (int i = 0; i < out.size(); i++) {
        vector<int> tmp = out[i];
        for (int j = 0; j < tmp.size(); j++) {
            cout << tmp[j] << " ";
        }
        cout << endl;
    }
}

void print_vec(vector<int> &vec)
{
   for (int j = 0; j < vec.size(); j++) {
        cout << vec[j] << " ";
    }
    cout << endl;
 
}

void findCombinations(vector<int> &arr, int index, int target, int sum, vector<int> &cur, vector<vector<int>> &out)
{
    if (sum > target) {
        return;
    } else if (sum == target) {
        out.push_back(cur);
    } else {
        for (int i = index; i < arr.size(); i++) {
            cur.push_back(arr[i]);
            findCombinations(arr, index, target, sum+arr[i], cur, out);
            cur.pop_back();
        }
    }
}

int main()
{
	int n = 5;
    vector<int> arr = {2,3,6,7};
    int target = 7;
    vector<int> cur;
	vector<vector<int>> out;

    cout << "arr size = " << arr.size() << endl;
	// recur all combination of numbers from 1 to n having sum n
	findCombinations(arr, 0, target, 0, cur, out);
    printCombination(out);
	return 0;
}