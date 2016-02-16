#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    /* multi_dimensional array malloc type 1 */
    int rows = 3;
    int cols = 5;
    int **arr1 = (int **)malloc(rows*sizeof(*arr1));
    if (!arr1)
        return -1;
    printf("malloc arr1\n");
    for (int i=0; i<rows; i++) {
        arr1[i] = (int *)malloc(cols*sizeof(**arr1));
        if (!arr1[i])
            return -1;
        printf("malloc arr1[%d]\n", i);
    }

    for (int i=0; i<rows; i++)
        for(int j=0; j<cols; j++) {
            arr1[i][j] = i*j;
        }

    for (int i=0; i<rows; i++) {
        free(arr1[i]);
        arr1[i] = NULL;
        printf("free arr1[%d]\n", i);
    }
    free(arr1);
    printf("free arr1\n");

    /* multi_dimensional array malloc type 2 */
    int (*arr2)[5] = (int (*)[5])malloc(rows*5*sizeof(int));
    if (!arr2)
        return -1;
    printf("malloc arr2\n");

    for (int i=0; i<rows; i++)
        for(int j=0; j<cols; j++) {
            arr2[i][j] = i*j;
        }

    free(arr2);
    printf("free arr2\n");

    return 0;
}
