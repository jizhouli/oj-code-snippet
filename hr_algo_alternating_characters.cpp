#include <string>
#include <vector>
#include <iostream>
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
    for(vector<string>::iterator it=strs.begin();it!=strs.end();it++){
        string s = *it;
        int duplicate_char_cnt = 0;
        for(int i=0;i<(s.length()-1);i++){
            if(s[i]==s[i+1])
                duplicate_char_cnt++;
        }
        cout << duplicate_char_cnt << endl;
    }
    return 0;
}
