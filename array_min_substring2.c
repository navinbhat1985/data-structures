#include  <stdio.h>
#include  <stdbool.h>
#include  <string.h>
#include  <limits.h>

const int MAX_CHARS = 256; 

int findMinWindow(char* str, char* ptr) 
{
    int len_str = strlen(str);
    int len_ptr = strlen(ptr);
    int ascii_str[256] = {0}; 
    int ascii_ptr[256] = {0};
    
    for (int i = 0; i < len_ptr; i++) {
        ascii_ptr[ptr[i]] = 1; 
    }
    
    int start = 0, count = 0, start_index = 0;
    int min_len = INT_MAX;
    for (int i = 0; i < len_str; i++) {
        ascii_str[str[i]]++;
        if (ascii_ptr[str[i]] != 0 && ascii_str[str[i]] <= ascii_ptr[str[i]]) 
            count++;
        if (count == len_ptr) {
            while (ascii_ptr[str[start]] == 0 || ascii_str[str[start]] > ascii_ptr[str[start]]) {
                if (ascii_str[str[start]] > ascii_ptr[str[start]])
                    ascii_str[str[start]]--;
                start++;
            }
            int win_len = i - start + 1;
            if (win_len < min_len) {
                min_len = win_len;
                start_index = start;
            }
        }
    }
    printf("Min window string is : ");
    for (int i = start_index; i < start_index+min_len; i++) 
        printf("%c", str[i]);
    printf("\n");
    return min_len;
} 

int main() 
{ 
    char str[] = {"ADOBECODEBANC"}; 
    char ptr[] = {"ABC"}; 
  
    printf("Smallest window is : %d\n", findMinWindow(str, ptr)); 
    return 0; 
} 

/* Try more Inputs
case 1: 
actual = findMinWindow("a","a")
expected = Smallest window is : a

case2: 
 actual = findMinWindow("zaaskzaa", "zsk")
 expected = Smallest window is : skz
 
case3: 
actual = findMinWindow("tutorial","oti")
expected = Smallest window is : tori

*/