//gcc 7.4.0

#include  <stdio.h>

int get_sqrt(int n) 
{
    int start = 0;
    int end = n;
    int mid = n/2;
    int res = 0;
    
    while (start <= end) {
        mid = (start+end)/2;
        printf("start %d mid %d end %d\n", start, mid, end);
        if (mid*mid == n) {
            res=mid;
            break;
        }
        
        if (n > mid*mid) {
            res = mid;
            start = mid+1;
        } else {
            end = mid-1;
        }
    }
    return res;
}
int main(void)
{
    int n = 64;
    printf("sqrt (%d) = %d\n", n, get_sqrt(n));
    return 0;
}