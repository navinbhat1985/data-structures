//g++  7.4.0

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

map<int, string> num_to_words;

void convert_to_words(int n)
{
    int val = n;
    int num_digits = 0;
    vector<int> vec;
    while (val) {
        int digit = val % 10;
        //printf(" %d \n", digit); 
        vec.push_back(digit);
        val = val / 10;
        num_digits++;
    }
    //cout << num_digits << endl;
    string words;
    while (!vec.empty()) {
        int sz = vec.size();
        string postfix = "";
        int digit = vec[sz-1]; vec.pop_back();
        switch (sz) {
            case 4:
                postfix = " thousand ";
                break;
            case 3:
                postfix = " hundred ";
                break;
            case 2:
                {
                    if (digit > 1) {
                        digit = digit * 10;
                    } else {
                        sz = vec.size();
                        int last_digit = vec[sz-1]; vec.pop_back();
                        digit = digit*10 + last_digit;
                    }
                }       
                break;
            default:
                postfix = "";
        }
        
        words += " " + num_to_words[digit] + " " + postfix;
        
    }
    cout << n << " - " << words << endl;
    
}

int main()
{
    num_to_words[1] = "one";
    num_to_words[2] = "two";
    num_to_words[3] = "three";
    num_to_words[4] = "four";
    num_to_words[5] = "five";
    num_to_words[6] = "six";
    num_to_words[7] = "seven";
    num_to_words[8] = "eight";
    num_to_words[9] = "nine";
    num_to_words[10] = "ten";
    num_to_words[11] = "eleven";
    num_to_words[12] = "twelve";
    num_to_words[13] = "thirteen";
    num_to_words[14] = "fourteen";
    num_to_words[15] = "fifteen";
    num_to_words[16] = "sixteen";
    num_to_words[17] = "seveteen";
    num_to_words[18] = "eighteen";
    num_to_words[19] = "nineteen";
    num_to_words[20] = "twenty";
    num_to_words[30] = "thirty";
    num_to_words[40] = "fourty";
    num_to_words[50] = "fifty";
    num_to_words[60] = "sixty";
    num_to_words[70] = "seventy";
    num_to_words[80] = "eighty";
    num_to_words[90] = "ninety";
    
    convert_to_words(1);
    convert_to_words(10);
    convert_to_words(19);
    convert_to_words(25);
    convert_to_words(255);
    convert_to_words(715);
    convert_to_words(705);
    convert_to_words(1214);
    convert_to_words(1234);
    convert_to_words(9999);
}