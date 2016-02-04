#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void produce_fib(int *fib, int size) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i=2;i<size;i++)
        fib[i] = fib[i-2] + fib[i-1];
}

int fibsrch(int arr[], int size, int key) {
    int fib_size = 48;
    int *fib = (int*)malloc(fib_size);
    produce_fib(fib, fib_size-1);
    fib[fib_size-1] = INT_MAX; //2^32/2-1

    int hit = -1;

    int k, mid, offs;
    k = 0;
    for(int i=0;i<fib_size;i++) {
        if (fib[i] > key) {
            k = i;
            break;
        }
    }

    offs = 0;
    while (k > 0) {
        mid = offs + fib[k-2];
        if (arr[mid] < key) {
            offs = mid;
            k = k-1;
        } else if (key < arr[mid]) {
            k = k-2;
        } else {
            hit = mid;
            break;
        }
    }

    free(fib);
    fib = NULL;
    return hit;
}

int main(int argc, char* argv[]) {
    int s[10000];
    for (int i=0;i<10000;i++)
        s[i] = i+1;
    
    int key, idx;

    key = 7989;
    printf("fib search iterative: %d\n", key);
    idx = fibsrch(s, sizeof(s)/sizeof(int), key);
    printf("hit %d\n", idx);

    key = 10100;
    printf("fib search iterative: %d\n", key);
    idx = fibsrch(s, sizeof(s)/sizeof(int), key);
    printf("hit %d\n", idx);
     
    return 0;
}
