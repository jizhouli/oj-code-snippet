#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]){
    int n;
    cin >> n;

    vector<string> strs;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        strs.push_back(s);
    }

    for(vector<string>::iterator it=strs.begin(); it!=strs.end(); it++){
        string s = *it;
        string output = "Funny";
        int len = s.length();
        for(int i=0; i<len/2; i++){
            //cout << s[i+1] << " - " << s[i] << " = " << abs(s[i+1] - s[i]) << endl;
            //cout << s[len-1-i-1+1] << " - " << s[len-1-i-1] << " = " << abs(s[len-1-i-1+1] - s[len-1-i-1]) << endl;
            if(abs(s[i+1] - s[i]) != abs(s[len-1-i-1+1]-s[len-1-i-1])){
                output = "Not Funny";
                break;
            }
        }
        cout << output << endl;
    }
    return 0;
}
