/*
 * BIT COUNT ALGORITHM
 * also known as: population count/popcount/sideways sum/hamming weight
 *
 * calculate usigned int(32bit) bit count
 * reference:
 *      http://www.cnblogs.com/graphics/archive/2010/06/21/1752421.html
 *      http://www.cnblogs.com/Martinium/archive/2013/03/01/popcount.html
 */

#include <iostream>
using namespace std;

// 原始算法
int bit_count1(unsigned int n){
    size_t cnt = 0;
    while(n>0){
        if ((n&1) == 1)
            cnt++;
        n>>=1;
    }
    return cnt;
}

// 稀疏算法
int bit_count2(unsigned int n){
    size_t cnt = 0;
    while(n>0){
        cnt++;
        n = n&(n-1);
    }
    return cnt;
}

// 密集算法
int bit_count3(unsigned int n){
    size_t cnt = sizeof(n)/sizeof(char) * 8;
    n = ~n;
    while(n>0){
        n = n&(n-1);
        cnt--;
    }
    return cnt;
}

// 动态查表算法
int bit_count4(unsigned int n){
    size_t cnt = 0;
    unsigned char table256[256] = {0};
    for(int i=0;i<sizeof(table256)/sizeof(table256[0]);i++){
        table256[i] = (i&1) + table256[i/2];
    }
    char *pc = (char*)&n;
    cnt = table256[pc[0]] + table256[pc[1]] + table256[pc[2]] + table256[pc[3]];
    return cnt;
}

// 静态查表算法（16/32位表）
int bit_count5(unsigned int n){
    size_t cnt = 0;
    unsigned int table16[16] =
    {
        0, 1, 1, 2,
        1, 2, 2, 3,
        1, 2, 2, 3,
        2, 3, 3, 4
    };
    while(n>0){
        cnt += table16[n&0xf];
        n>>=4;
    }
    return cnt;
}

// 并行算法
int bit_count6(unsigned int n){
    n = (n&0x55555555) + ((n>>1)&0x55555555);
    n = (n&0x33333333) + ((n>>2)&0x33333333);
    n = (n&0x0f0f0f0f) + ((n>>4)&0x0f0f0f0f);
    n = (n&0x00ff00ff) + ((n>>8)&0x00ff00ff);
    n = (n&0x0000ffff) + ((n>>16)&0x0000ffff);
    return n;
}

// TODO and more...

int bit_count7(unsigned int n){
    size_t cnt = 0;
    return cnt;
}

int bit_count8(unsigned int n){
    size_t cnt = 0;
    return cnt;
}

int main(int argc, char* argv[]){
    unsigned int n = 0x0f0f;
    cout << "bc1 "<< n << " : "<< bit_count1(n) << endl;
    cout << "bc2 "<< n << " : "<< bit_count2(n) << endl;
    cout << "bc3 "<< n << " : "<< bit_count3(n) << endl;
    cout << "bc4 "<< n << " : "<< bit_count4(n) << endl;
    cout << "bc5 "<< n << " : "<< bit_count5(n) << endl;
    cout << "bc6 "<< n << " : "<< bit_count6(n) << endl;
    cout << "bc7 "<< n << " : "<< bit_count7(n) << endl;
    cout << "bc8 "<< n << " : "<< bit_count8(n) << endl;
    return 0;
}
