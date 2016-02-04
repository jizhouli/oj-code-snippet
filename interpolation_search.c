#include <stdio.h>
#include <stdlib.h>

int midpoint(int s[], int key, int l, int r) {
    int m = l + (r-l) * (key-s[l]) / (s[r]-s[l]);
    printf("key %d s[l] %d s[r] %d l %d r %d m %d\n",
           key, s[l], s[r], l, r, m);
    m = l < m ? m : l;
    m = m < r ? m : r;
    return m;
}

int interpolation_search_recursive(int s[], int key, int l, int r) {
    if (r<l) {
        printf("isr no exist\n");
        return -1;
    }
    int m = midpoint(s, key, l, r);
    if (key < s[m]) {
        printf("isr <- %d %d\n", l, m-1);
        return interpolation_search_recursive(s, key, l, m-1);
    }
    else if (s[m] < key) {
        printf("isr -> %d %d\n", m+1, r);
        return interpolation_search_recursive(s, key, m+1, r);
    }
    else {
        printf("isr found %d\n", m);
        return m;
    }
}

int interpolation_search_iterative(int s[], int key, int l, int r) {
    while (l < r) {
        printf("isi %d %d\n", l, r);

        int m = midpoint(s, key, l, r);
        if (key < s[m])
            r = m - 1;
        else if (s[m] < key)
            l = m + 1;
        else
            return m;
    }
    printf("isi no exist\n");
    return -1;
}

int main(int argc, char* argv[]) {
    int s[] = {1,2,3,4,5,6,7,8,9,10};
    
    int key, idx;

    key = 8;
    printf("interpolation search recursive: %d\n", key);
    idx = interpolation_search_recursive(s, key, 0, 9);

    key = 11;
    printf("interpolation search recursive: %d\n", key);
    idx = interpolation_search_recursive(s, key, 0, 9);
     
    key = 8;
    printf("interpolation search iterative: %d\n", key);
    idx = interpolation_search_iterative(s, key, 0, 9);

    key = 11;
    printf("interpolation search iterative: %d\n", key);
    idx = interpolation_search_iterative(s, key, 0, 9);
     
    return 0;
}
