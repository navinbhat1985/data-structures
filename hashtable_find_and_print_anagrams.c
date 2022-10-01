#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
 

void printAnagram(unordered_map<string,
                  vector<string> >& store)
{
    //Practise Yourself : Write your code Here
}
 
// function for storing
// the vector of strings into HashMap
void storeInMap(vector<string>& vec)
{
    unordered_map<int,vector<string>> store;
    for (int i = 0; i < vec.size();i++) {
        string str = vec[i];
        int key = 0;
        for (int j = 0; j < str.size();j++) {
            key = key ^ str[j];
        }
        //cout << vec[i] << " key " << key << endl;
        store[key].push_back(str);
    }
    
    cout << "Anagrams in the list are: " << endl;
    for (auto const &pair: store) {
        for (int i = 0; i < pair.second.size(); i++) {
            cout << pair.second[i] << " ";
        }
        cout << endl;
    }
}
 

int main()
{
    // initialize vector of strings
    vector<string> arr;
    arr.push_back("eat");
    arr.push_back("tea");
    arr.push_back("tan");
    arr.push_back("ate");
    arr.push_back("nat");
    arr.push_back("bat");
  
 
    // utility function for storing
    // strings into hashmap
    storeInMap(arr);
    return 0;
}

/* Try more Inputs
Case 1:
        vector<string> arr;
        arr.push_back("cat");
        arr.push_back("dog");
        arr.push_back("tac");
        arr.push_back("got");
        arr.push_back("act");
  
 
        storeInMap(arr);
        expected = [[cat, tac, act],[dog],[got]]


Case2: 
        vector<string> arr;
        arr.push_back("no");
        arr.push_back("on");
        arr.push_back("is");

        storeInMap(arr);
        expected = [["no","on"] ["is"]]

*/
