#include <stdio.h>

#include <time.h>
#include <stdlib.h>

void quick_sort(int s[], int l, int r)
{
    if (l >= r)
        return;
    printf("pivot: %d (%d, %d)\n", s[l], l, r);

    int i = l, j = r, x = s[l];
    while(i < j)
    {
        while (i<j && x<=s[j]) j--;
        if (i < j)
            s[i++] = s[j];

        while (i<j && s[i]<x) i++;
        if (i < j)
            s[j--] = s[i];
    }
    s[i] = x;
    quick_sort(s, l, i-1);
    quick_sort(s, i+1, r);
}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    printf("hello world\r\n");

    int iArr[20];
    for(int i=0; i<20; i++)
    {
        iArr[i] = rand()%100;
        printf("%d ", iArr[i]);
    }

    printf("\nquick sort\n");
    quick_sort(iArr, 0, 19);
    for (int i=0; i<20; i++)
        printf("%d ", iArr[i]);
    printf("\ndone\n");
}
