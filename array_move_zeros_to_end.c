#include <stdio.h>
 
void moveZeroToTheEnd(int a[], int n)
{
    int zp = 0 , nzp = 0;
    while (zp < n && nzp < n) {
        if (a[zp] == 0) {
            if (a[nzp] != 0) {
                a[zp] ^= a[nzp];
                a[nzp] ^= a[zp];
                a[zp] ^= a[nzp];
                zp++;
            }
            nzp++;
        } else {
            zp++;
            nzp++;
        }
    }
} 

int main()
{
    int array1[] = {1,3,0,0,4,0,9};
    int n = (sizeof(array1) / sizeof(array1[0]));
    moveZeroToTheEnd(array1, n);
    printf("Result is :\n");
    for (int i = 0; i < n; i++)
        printf("%d ", array1[i]);
    printf("\n");
    return 0;
}
