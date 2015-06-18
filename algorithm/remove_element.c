#include<stdio.h>
#include<stdbool.h>
typedef struct _label {
    int index;
    bool flag;
} Label;

int removeElement(int* nums, int numsSize, int val) {
    if (numsSize == 0) return 0;
    
    /*
    int i = 0; // next hole
    int j = numsSize-1; // forward carrot
    while (i<=j) {
        while((i<j) && (nums[i]!=val)) i++;
        while((i<j) && (nums[j]==val)) j--;
        if (i<j) nums[i]=nums[j--];
    }
    return i+1;
    */
    Label hole, carrot;
    hole.index = 0;
    hole.flag = false;
    carrot.index = numsSize-1;
    carrot.flag = false;

    while (hole.index <= carrot.index) {
        printf("hole %d carrot %d\n", hole.index, carrot.index);
        while (hole.index<=carrot.index) {
            if (nums[hole.index] == val) {
                hole.flag = true;
                break;
            }
            hole.index++;
        }
        if (!hole.flag)
            break;
        while (hole.index<=carrot.index) {
            if (nums[carrot.index] != val) {
                carrot.flag = true;
                break;
            }
            carrot.index--;
        }
        if (!carrot.flag)
            break;
        nums[hole.index] = nums[carrot.index];
        hole.flag = false;
        carrot.flag = false;
        hole.index++;
        carrot.index--;
    }
    return hole.index;
}

int main(void) {
    int array[10] = {3};
    int val = 5;
    //int array[1] = {1};
    //int val = 1;
    int newLen = removeElement(array, sizeof(array)/sizeof(array[0]), val);
    printf("%d\n", newLen);
}
