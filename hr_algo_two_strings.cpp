#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]){
    int n;
    vector<pair<string, string> > texts;

    cin >> n;
    for(int i=0; i<n; i++){
        pair<string, string> strs;
        string str1, str2;
        cin >> str1 >> str2;
        strs = make_pair(str1, str2);
        texts.push_back(strs);
    }

    for(vector<pair<string, string> >::iterator it=texts.begin(); it!=texts.end(); it++){
        unsigned int alphebit_signs_1 = 0;
        unsigned int alphebit_signs_2 = 0;
        string str1 = (*it).first;
        string str2 = (*it).second;

        for(int i=0;i<str1.length();i++){
            alphebit_signs_1 |= 1 << (str1[i]-'a');

            if (alphebit_signs_1 == (2^27-1))
                break;
        }

        for(int i=0;i<str2.length();i++){
            alphebit_signs_2 |= 1 << (str2[i]-'a');

            if (alphebit_signs_2 == (2^27-1))
                break;
        }

        if((alphebit_signs_1 & alphebit_signs_2) != 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
