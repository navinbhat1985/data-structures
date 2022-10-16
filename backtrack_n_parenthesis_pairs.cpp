# include<iostream>
# include<vector>
using namespace std;

# define MAX_COUNT 100

char output[256] = {0};

void printParenthesesPairs(int pos, int n, int open, int close)
{
    if (close >= n) {
        for (int i = 0; i <= pos; i++) {
            cout << output[i] ;
        }
        cout << endl;
        return;
    }
    if (open > close) {
        output[pos] = '}';
        printParenthesesPairs(pos+1, n, open, close+1);
    }
    if (open < n) {
        output[pos] = '{';
        printParenthesesPairs(pos+1, n, open+1, close);
    }
    return;
}

int main() {
   int n = 5;
   cout<<"All parentheses pairs of length "<<n<<" are:\n";
   if(n > 0)
      printParenthesesPairs(0, n, 0, 0);
   return 0;
}

/*
  test_validParenthesis_1():
        n = 3;
        str = [""] * 2 * n;
        actual = printParenthesis(str,n)
        expected = ["((()))","(()())", "(())()", "()(())", "()()()"]
        self.assertEqual(actual, expected) 

     test_validParenthesis_2():
        n = 2;
        str = [""] * 2 * n;
        actual = printParenthesis(str,n)
        expected = ["(())","()()"]
        self.assertEqual(actual, expected) 
*/