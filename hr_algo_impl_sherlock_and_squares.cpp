#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]){
    int n;
    cin >> n;

    vector<vector<int> > input(
        n,
        vector<int>(2, 0)
    );
    for(int i=0;i<n;i++){
        vector<int> l(2, 0);
        int m,n;
        cin >> m >> n;
        l[0] = m;
        l[1] = n;
        input[i] = l;
    }

    for(vector<vector<int> >::iterator it=input.begin();it!=input.end();it++){
        int b = (*it)[0];
        int e = (*it)[1];

        int b_sqrt = (int)sqrt(double(b));
        int e_sqrt = (int)sqrt(double(e));
        int num = e_sqrt - b_sqrt;
        if (pow(b_sqrt, 2) == b)
            num++;
        cout << num << endl;
    }
    return 0;
}
