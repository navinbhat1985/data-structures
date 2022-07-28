
void reverse (int* a, int size)
{
    int i = 0, j = size-1;
    while(i < j) {
        a[i] ^= a[j];
        a[j] ^= a[i];
        a[i] ^= a[j];
        i++;
        j--;
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    reverse(digits, digitsSize);
    for (int i = 0; i < digitsSize; i++) {
        digits[i] += 1;
        if (digits[i] < 10) {
            break;
        }
        digits[i] = 0;
    }
    if (digits[digitsSize-1] == 0) {
        digits = realloc(digits, (++digitsSize) * sizeof(int));
        digits[digitsSize-1] = 1;
    }
    reverse(digits, digitsSize);
    *returnSize = digitsSize;
    return digits;
}



int* plusOne(int* digits, int digitsSize, int* returnSize){
    int carry = 0;
    for (int i = digitsSize-1; i >= 0; i--) {
        digits[i] += 1;
        if (digits[i] < 10) {
            break;
        }
        digits[i] = 0;
        if (i == 0)
            carry = 1;
    }
    *returnSize = digitsSize + carry;
    int *a;
    if (carry) {
        a = malloc(*returnSize * sizeof(int));
        a[0] = carry;
        for (int i = 0; i < digitsSize; i++) {
            a[i + carry] = digits[i];
        }
    } else {
        a = digits;
    }
    return a;
}


int* plusOne(int* digits, int digitsSize, int* returnSize){
    int carry = 0;
    for (int i = digitsSize-1; i >= 0; i--) {
        digits[i] += 1;
        if (digits[i] < 10) {
            break;
        }
        digits[i] = 0;
        if (i == 0)
            carry = 1;
    }
    *returnSize = digitsSize + carry;
    int* a = malloc(*returnSize * sizeof(int));
    a[0] = carry;
    for (int i = 0; i < digitsSize; i++) {
        a[i + carry] = digits[i];
    }
    return a;
}