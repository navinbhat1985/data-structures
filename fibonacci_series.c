#include  <stdio.h>

// fibonacci numbers: 0 1 1 2 3 5 8 13 21... 

int fib_iterate(int n)
{
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-2] + fib[i-1];
        printf("fib[%d] = %d\n", i, fib[i]);
    }
    return fib[n];
}

int fib_recur(int n)
{
    if (n < 2)
        return n;
    return(fib_recur(n-2) + fib_recur(n-1));
}

int main(void)
{
    int  n = 8;
    printf("fib_iterate(%d) = %d\n", n, fib_iterate(n));
    printf("fib_recur(%d) = %d\n", n, fib_recur(n));
    
    return 0;
}