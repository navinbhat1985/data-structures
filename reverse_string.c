//gcc 7.4.0

#include  <stdio.h>
#include  <string.h>

char* reverse(char* s)
{
    if (!s)
        return NULL;
    int len = strlen(s);
    for (int i = 0; i < len/2; i++) {
        s[i] ^= s[len-i-1];
        s[len-i-1] ^= s[i];
        s[i] ^= s[len-i-1];
    }
    return s;
}

char* reverse_r(char*s, int len)
{
    if (len <= 1)
        return s;
    // swap with last char
    char tmp = s[0];
    s[0] = s[len - 1];
    s[len - 1] = tmp;
    reverse_r(s+1, len-2);
    return (s);
}

int main(void)
{
    char str[100] = {"Navin Bhat"};
    printf ("reversed: %s\n", reverse(str));
    printf ("original: %s\n", reverse(str));
    
    printf ("reversed_r: %s\n", reverse_r(str, strlen(str)));
    printf ("original_r: %s\n", reverse_r(str, strlen(str)));
    return 0;
}