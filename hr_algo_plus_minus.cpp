#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }

    if (n < 1)
        return 1;
    int positive_numbers = 0;
    int negative_numbers = 0;
    int zero_numbers = 0;
    for(vector<int>::iterator it=arr.begin();it!=arr.end();it++){
        if(*it > 0)
            positive_numbers+=1;
        else if(*it < 0)
            negative_numbers+=1;
        else
            zero_numbers+=1;
    }
    printf("%.6f\n", float(positive_numbers)/n);
    printf("%.6f\n", float(negative_numbers)/n);
    printf("%.6f\n", float(zero_numbers)/n);
    return 0;
}

