#include <vector>
#include <iostream>
using namespace std;

int find_digits(int n){
    int digits = 0;
    int r = n;
    while(r>0){
        int d = r%10;
        r = r/10;
        if ((d!=0) && (n%d==0))
            digits++;
        //cout << d << " "<< digits << endl;
    }
    return digits;
}

int main(int argc, char* argv[]){
    int cnt;
    cin >> cnt;

    vector<int> nums;
    for(int i=0;i<cnt;i++){
        int n;
        cin >> n;
        nums.push_back(n);
    }

    for(vector<int>::iterator it=nums.begin();it!=nums.end();it++){
        int digits = find_digits(*it);
        cout << digits << endl;
    }
    return 0;
}
