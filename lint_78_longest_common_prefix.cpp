#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        string lcp;
        int min_len = -1;
        for(vector<string>::iterator it=strs.begin(); it!=strs.end(); it++){
            if(min_len<0)
                min_len = (*it).length();
            else
                min_len = ((*it).length() < min_len) ? (*it).length() : min_len;
        }

        for(int i=0;i<min_len;i++){
            bool end = false;
            char c = 0;
            for(vector<string>::iterator it=strs.begin(); it!=strs.end(); it++){
                if(!c)
                    c = (*it)[i];
                else
                    if(c!=(*it)[i]){
                        end = true;
                        break;
                    }
            }
            if(end)
                break;
            lcp.push_back(c);
        }
        return lcp;
    }
};

int main(int argc, char* argv[]){
    vector<string> strs;
    strs.push_back("ABCDEFG");
    strs.push_back("ABCEFG");
    strs.push_back("ABCEFA");

    Solution sol;
    string lcp = sol.longestCommonPrefix(strs);
    cout << "longest common prefix is " << lcp << endl;
    return 0;
}
