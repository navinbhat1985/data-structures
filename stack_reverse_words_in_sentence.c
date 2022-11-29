#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char* s, int i, int j)
{
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}

void reverse(char *s, int begin, int end)
{
    while(begin < end) {
        swap(s, begin++, end--);
    }
}
void reverseWords(char* s)
{
    int len = strlen(s);
    int start = 0;
    int end = 0;
    printf(" len %d\n", len);
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            reverse(s, start, end);
            start = i+1;
        } else {
            end = i;
        }
    }
    printf("start %d end %d\n", start, end);
    reverse(s, start, end);
    printf("Reveresed words - %s\n", s);
    reverse(s, 0, end);
}
 

int main()
{
    char s[] = "   the sky is blue  ";
    printf("Original - %s|\n", s);
    reverseWords(s);
    printf("Reversed - %s|\n", s);
    return 0;
}