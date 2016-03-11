#include <iostream>
#include <vector>
using namespace std;

int get_height(int n){
    int height = 1;
    for(int i=0;i<n;i++){
        if(i%2 == 0)
            height*=2;
        else
            height+=1;
    }
    return height;
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
        int height = get_height(*it);
        cout << height << endl;
    }
    return 0;
}
