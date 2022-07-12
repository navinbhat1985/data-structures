//gcc 7.4.0

#include  <stdio.h>
#include  <stdbool.h>
#include  <stdlib.h>


typedef struct hash_bucket {
    int key;
    int data;
    struct hash_bucket* next; /* LL Chaining to handle collisions */
} hash_bucket;

/*
    1. Prime numbers are numbers which are only divisible by 1 and itself.
    2. The only even prime number is 2
    Examples: 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47.. etc
*/
bool is_prime(int n)
{
    bool prime = false;
    /* prime numbers start from 2 */
    if (n <= 1) {
        return prime;
    }
    prime = true;
    /* All the factors for any integer 'n' are between 2 to n/2 */
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            prime = false;
            break;
        }
    }
    return prime;
}

int get_nearest_prime(int n)
{
    /* if number less than 2, return 1st prime(2) */
    if (n <= 2) {
        return 2;
    }
    /* if number is even, increment to make it odd */
    if (n % 2 == 0) {
        n++;
    }
    /* Check if n is prime, else check the next odd number */
    while(!is_prime(n)) {
        n += 2;
    }
    return n;
}

int hash_function(int key, int size) {
    /* A hash can be derived from the key and then modulo to size of hash table */
    return (key % size);
}

hash_bucket* htbl_create(int size) {
    hash_bucket* hash_table = calloc(size, sizeof(hash_bucket));
    return hash_table;
}

int htbl_insert(int key, int data, hash_bucket* htable, int size)
{
    int index = hash_function(key, size);
    if (htable[index].key == 0) {
        htable[index].key = key;
        htable[index].data = data;
        printf("key %d data %d inserted at index %d\n", key, data, index);
    } else if (htable[index].key == key) {
        htable[index].data = data;
        printf("key %d data %d updated at index %d\n", key, data, index);
    } else {
        //Collision
        printf("Collision at index %d!! failed to insert key %d data %d\n", index, key, data);
        return -1;
    }
    
    return 0;
}

int htbl_remove(int key, hash_bucket* htable, int size)
{
    int index = hash_function(key, size);
    if (htable[index].key == key) {
        htable[index].key = 0;
        htable[index].data = 0;
        printf("key %d removed at index %d\n", key, index);
    } else {
        /* Collision and we need to traverse the chain or it is a key which was never inserted */
        printf("Key doesnt match at index %d!! failed to remove key %d\n", index, key);
        return -1;
    }
    
    return 0;
}

int htbl_get(int key, int *data, hash_bucket* htable, int size)
{
    int ret = -1;
    int index = hash_function(key, size);
    if (htable[index].key == key) {
        *data = htable[index].data;
        printf("key %d found at index %d data is %d\n", key, index, *data);
        ret = 0;
    } else {
        /* Collision and we need to traverse the chain or it is a key which was never inserted */
        printf("key doesnt match at index %d!! failed to get data for key %d\n", index, key);
        return -1;
    }
    return ret;
}

int htbl_print(hash_bucket* htable, int size)
{
    printf("\nprint hash table of size %d\n", size);
    for (int i = 0; i < size; i++) {
        if (htable[i].key != 0) {
            printf("index %d key %d data %d\n", i, htable[i].key, htable[i].data);
        }
    }
    return 0;
}

int main(void)
{
    printf("Nearest prime from 0-50\n");
    for (int i = 0 ; i < 50; i++) {
       printf("%d, ", get_nearest_prime(i));
    }
    printf("\nList of all primes\n");
    for (int i = 0 ; i < 50; i++) {    
        if (is_prime(i))
           printf("%d\n", i);
    }
    /* Create a hash table */
    int size = get_nearest_prime(100);
    printf("create hash table of size %d\n", size);
    hash_bucket* htbl = htbl_create(size);
    /* Insert some key, values in hash table */
    htbl_insert(10, 11, htbl, size);
    htbl_insert(11, 22, htbl, size);
    htbl_insert(11, 33, htbl, size);
    htbl_insert(12, 44, htbl, size);
    htbl_insert(13, 55, htbl, size);
    htbl_insert(101, 66, htbl, size);
    htbl_insert(  0, 66, htbl, size);
    
    htbl_print(htbl, size);
    
    /* Get the data at key from htable */
    int data = 0;
    htbl_get(10, &data, htbl, size);
    htbl_get(11, &data, htbl, size);
    htbl_get(12, &data, htbl, size);
    htbl_get(13, &data, htbl, size);
    htbl_get(101, &data, htbl, size);
    htbl_get(100, &data, htbl, size);
    htbl_get(0, &data, htbl, size);

    /* Remove some keys from htbl */
    htbl_remove(0, htbl, size);
    htbl_remove(10, htbl, size);
    htbl_remove(11, htbl, size);
    htbl_remove(12, htbl, size);
    htbl_remove(13, htbl, size);
    htbl_remove(101, htbl, size);
    
    return 0;
}