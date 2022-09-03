#include <stdio.h> 
#include <stdbool.h>  
void printArray (int arr[], int n); 
  

int exceptionCheckAll9s (int num[], int n ); 
  
// Returns next palindrome of a given number num[]. 
// This function is for input type 2 and 3 
void nextPalindromeProblem (int num[], int n ) 
{ 
     //Practise Yourself : Write your code Here
     
} 
  
// The function that prints next palindrome of a given number num[] 
// with n digits. 
void generateNextPalindrome( int num[], int n ) 
{ 
    int is_even = false;
    int right, middle, left;
    if (n%2 == 0) {
        is_even = true;
        middle = (n-1)/2;
        left = middle;
        right = middle+1;
    } else {
        middle = (n-1)/2;
        left = middle-1;
        right = middle+1;
    }
    bool once = false;
    while (left >=0 && right <= n-1) {
        // TODO exception check for all 9's
        if (num[left] <= num[right]) {
            if (!once) {
                if (is_even) {
                    num[left]++;
                    if (num[left] == 10) {
                        num[left] = 0;
                        num[left-1]++;
                    }
                } else {
                    num[middle]++;
                    if (num[middle] == 10) {
                        num[middle] = 0;
                        num[middle-1]++;
                        num[middle+1] = num[middle-1];
                    }
                }
                once = true;
            }
        }
        num[right] = num[left];
        left--;
        right++;
    }
} 
  
void printArray(int arr[], int n) 
{ 
    int i; 
    for (i=0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
int main() 
{ 
    int num[] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2}; 
   //int num[] = {1, 2, 1}; 
    //int num[] = {2,3,5,4,5};
    int n = sizeof (num)/ sizeof(num[0]); 
    printf("Original array:");
      printArray(num, n);
    generateNextPalindrome( num, n ); 
    printf("Next palindrome:");
      printArray(num, n);
  
    return 0; 
} 


/* Try more Inputs
case 1: 
actual = nextPalindromeProblem([9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2],11)
expected = 94188088149

case2: 
 actual = nextPalindromeProblem([1,2,1],3)
 expected = 131
 
case3: 
actual = nextPalindromeProblem([2,3,5,4,5],5)
expected = 23632
*/