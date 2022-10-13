
#include <stdio.h>

// recursive solution to calculate pow(x, n)
// using Divide & Conquer
int power(int x, unsigned n)
{
    if (n == 0)
        return 1;
    if (n%2 == 0) {
        return (power(x,n/2) * power(x,n/2));
    } else {
        return (x * power(x,n/2) * power(x,n/2));
    }
}

int main(void)
{
	int x = 2;
	unsigned n = 10;

	printf("pow(%d,%d) = %d", x, n, power(x, n));

	return 0;
}