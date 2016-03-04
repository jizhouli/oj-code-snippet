#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int brute_force_max_xor(int l, int r){
    int max_xor = 0;
    for(int i=l;i<=r;i++)
        for(int j=l;j<=i;j++)
            if (max_xor < (i^j))
                max_xor = (i^j);
    return max_xor;
}

int max_xor(int l, int r){
    int i = 1;
    while (l != r) { l /= 2; r /= 2; i *= 2; }
    return i - 1;
}

int max_xor2(int l, int r){
    int i = 1;
    int n = l^r;
    while(n>0) { n>>=1; i<<=1;}
    return i-1;
}

int maxXor(int l, int r){
    return max_xor2(l, r);
}

int main(int argc, char* argv[]){
    int res;
    int l,r;
    cin >> l >> r;

    res = maxXor(l, r);
    cout << res;

    return 0;
}
