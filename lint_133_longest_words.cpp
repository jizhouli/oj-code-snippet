#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        vector<string> words;
        int max_len = 0;
        for (vector<string>::iterator it=dictionary.begin(); it!=dictionary.end(); it++) {
            int len = (*it).length();
            if (len < max_len)
                continue;
            if (len > max_len) {
                max_len = len;
                words.clear();
            }
            words.push_back(*it);
        }
        return words;
    }
};

int main(int argc, char* argv[]) {
    vector<string> dict;
    dict.push_back("dog");
    dict.push_back("google");
    dict.push_back("facebook");
    dict.push_back("internationalization");
    dict.push_back("blabla");

    dict.clear();
    dict.push_back("like");
    dict.push_back("love");
    dict.push_back("hate");
    dict.push_back("yes");
    dict.push_back("haha");
    dict.push_back("go");

    Solution sol;
    vector<string> words = sol.longestWords(dict);
    for (vector<string>::iterator it=words.begin(); it!=words.end(); it++)
        cout << *it << endl;

    return 0;
}
