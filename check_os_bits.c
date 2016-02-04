#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    long int iMax32 = pow(2, (32-1))-1;//2^(32-1)-1;
    long int iMax16 = pow(2, (16-1))-1;//2^(16-1)-1;
    
    if ((iMax32+1) > iMax32)
        printf("os 64 bits (%ld, %ld)\n", iMax32, iMax32+1);
    else if ((iMax16+1) > iMax16)
        printf("os 32 bits (%ld, %ld)\n", iMax16, iMax16+1);
    else
        printf("os 16 bits\n");
}
