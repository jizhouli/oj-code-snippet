#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    vector<bool> cancels(t, false);

    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;

        int ontime = 0;
        vector<int> a(n);
        for(int a_i = 0;a_i < n;a_i++){
           cin >> a[a_i];
           if (a[a_i] <= 0)
               ontime++;
        }
        if (ontime < k)
            cancels[a0] = true;
    }
    for(int i=0; i<t; i++){
        if (cancels[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
