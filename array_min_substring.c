//gcc 7.4.0

#include  <stdio.h>
#include  <string.h>
#include  <stdbool.h>

const int no_of_chars = 256; 
  
// Function to find smallest window containing 
// all characters of 'ptr' 
int findMinWindow(char* str, char* ptr) 
{ 
    int len_str = strlen(str);
    int len_ptr = strlen(ptr);
    
    int min_size = len_str;
    bool match_found = false;
    int win_start = -1;
    int win_size = 0;
    int win_end = 0;
    int match_needed = len_ptr;
    int uniq_match = 0;
    int ascii_ptr[256] = {0};
    int ascii_str[256] = {0};
    
    for (int i = 0; i < len_ptr; i++) {
        ascii_ptr[ptr[i]] = 1;
    }
    for (int i = 0; i < len_str; i++) {
        if (ascii_ptr[str[i]] == 0) {
            if (win_start >= 0) {
                win_size++;
            }
            continue;
        }
        if (win_start == -1) {
            win_start = i;
            printf("win_start at %d\n", i);
        }
        ascii_str[str[i]]++;
        if (ascii_str[str[i]] == 1) {
            uniq_match++;
        }
        win_size++;
        while (uniq_match >= match_needed) {
            win_end = i;
            if (win_size < min_size) {
                min_size = win_size;
                printf("Found match at start %d, end %d, min_size %d\n", win_start, win_end, min_size);
            } else {
                printf("Found win_cur_size %d >= min_size %d\n", win_size,  min_size);
            }
            /*DEUBG start*/
            printf("Matched window is ");
            for (int j = win_start; j <= win_end; j++)
                printf("%c", str[j]);
            printf("\n");
            /*DEBUG end*/
            /* start a new window */
            ascii_str[str[win_start]]--;
            if (ascii_str[str[win_start]] == 0)
                uniq_match--;

            win_start++; win_size--;
            while (win_start < win_end) {
                if (ascii_ptr[str[win_start]] >= 1)
                    break;
                win_start++;
                win_size--;
            }
            printf("new window start %d, win_end %d , win_size %d, uniq_match %d\n", win_start, win_end, win_size, uniq_match);
        } 
    }
    return min_size;
} 
  

int main() 
{ 
    char str[] = {"ADOBECODEBANC"}; 
    char ptr[] = {"ABC"}; 
    //char str[] = {"zaaskzaa"}; 
    //char ptr[] = {"zsk"}; 
    //char str[] = {"tutorial"}; 
    //char ptr[] = {"oti"}; 
    //char str[] = {"aaabbcaabcbabca"}; 
    //char ptr[] = {"bc"}; 
    printf("%s %s\n", str, ptr);
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
