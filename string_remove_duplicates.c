#include <stdio.h>
#include <string.h>

// Function to remove duplicates
void removeDuplicates(char* str)
{
    int ascii[256] = {0};
    int len = strlen(str);
    for (int i = 0 ; i < len; i++) {
        int index = str[i];
        if (-1 != ascii[index]) {
            ascii[index] = -1;
        } else {
            str[i] = ' ';
        }
    }
    printf("%s\n", str);
}
 
int main()
{
    char str[] = "bcabc";
    removeDuplicates(str);
    return 0;
}