#include <iostream>
#include <string>
#include <climits> // UINT_MAX
using namespace std;

int main(int argc, char* argv[]){
    string text;
    //cin >> text;
    getline(cin, text);

    /* BIT MANIPULATION */
    unsigned int alphabet_signs_bit = 0;
    for(int i = (sizeof(unsigned int)/sizeof(char)*8); i>=26; i--){
        alphabet_signs_bit |= 1 << i;
    }

    for(int i=0;i<text.length();i++){
        if(('a' <= text[i]) && (text[i] <='z'))
            alphabet_signs_bit |= 1 << (text[i] - 'a');
        else if(('A' <= text[i]) && (text[i] <='Z'))
            alphabet_signs_bit |= 1 << (text[i] - 'A');
    }

    if (alphabet_signs_bit == UINT_MAX)
        cout << "pangram" << endl;
    else
        cout << "not pangram" << endl;

    /*
    bool is_pangram = true;
    bool alphabet_signs[26] = {false};
    for(int i=0;i<text.length();i++){
        if(('a' <= text[i]) && (text[i] <='z'))
            alphabet_signs[text[i] - 'a'] = true;
        else if(('A' <= text[i]) && (text[i] <='Z'))
            alphabet_signs[text[i] - 'A'] = true;
    }

    for(int i=0;i<sizeof(alphabet_signs)/sizeof(alphabet_signs[0]);i++)
        if(!alphabet_signs[i]){
            is_pangram = false;
            //cout << char(i+'a') << endl;
        }

    if (is_pangram)
        cout << "pangram" << endl;
    else
        cout << "not pangram" << endl;
    */

    return 0;
}
