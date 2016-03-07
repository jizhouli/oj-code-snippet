#include <stdio.h>
#include <stdlib.h>

int binary_search_recursive(int s[], int key, int l, int r) {
    if (r<l) {
        printf("bsr no exist\n");
        return -1;
    }
    int m = l + (r-l)/2;
    if (key < s[m]) {
        printf("bsr %d %d\n", l, m-1);
        return binary_search_recursive(s, key, l, m-1);
    }
    else if (s[m] < key) {
        printf("bsr %d %d\n", m+1, r);
        return binary_search_recursive(s, key, m+1, r);
    }
    else {
        printf("bsr found %d\n", m);
        return m;
    }
}

int binary_search_iterative(int s[], int key, int l, int r) {
    while (l < r) {
        printf("bsi %d %d\n", l, r);

        int m = l + (r-l)/2;
        if (key < s[m])
            r = m - 1;
        else if (s[m] < key)
            l = m + 1;
        else
            return m;
    }
    printf("bsi no exist\n");
    return -1;
}

int main(int argc, char* argv[]) {
    int s[] = {1,2,3,4,5,6,7,8,9,10};
    
    int key, idx;

    key = 8;
    printf("binary search recursive: %d\n", key);
    idx = binary_search_recursive(s, key, 0, 9);

    key = 11;
    printf("binary search recursive: %d\n", key);
    idx = binary_search_recursive(s, key, 0, 9);
     
    key = 8;
    printf("binary search iterative: %d\n", key);
    idx = binary_search_iterative(s, key, 0, 9);

    key = 11;
    printf("binary search iterative: %d\n", key);
    idx = binary_search_iterative(s, key, 0, 9);
     
    return 0;
}
