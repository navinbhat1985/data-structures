//gcc 7.4.0

#include  <stdio.h>

int fact_i(int n)
{
    int fact = 1;
    for(int i = n; i > 0; i--){
        fact = fact * i;
    }
    return fact;
}

int fact_r(int n)
{
    if (n == 1)
        return 1;
    int fact = 1;
    fact = n * fact_r(n-1);
    return(fact);
}

int main(void)
{
    printf("Hello, world!\n");
    printf("fact_i %d\n", fact_i(3));
    printf("fact_r %d\n", fact_r(3));
    
    
    return 0;
}