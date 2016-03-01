#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        int lcs_cnt = 0;
        if (!A.length() or !B.length())
            return lcs_cnt;

        int ta_len = A.length() + 1;
        int tb_len = B.length() + 1;
        vector<vector<int> > array(
            ta_len,
            vector<int>(tb_len, 0)
        );
        for(int i=1;i<ta_len;i++)
            for(int j=1;j<tb_len;j++){
                if(A[i-1] == B[j-1]){
                    array[i][j] = array[i-1][j-1] + 1;
                    if(array[i][j]>lcs_cnt)
                    lcs_cnt = (array[i][j]>lcs_cnt) ? array[i][j] : lcs_cnt;
                }
                else
                    array[i][j] = 0;
            }
        return lcs_cnt;
    }
};

int main(int argc, char* argv[]){
    string s1 = "ABCD";
    string s2 = "CBCE";
    Solution sol;
    int lcs_cnt = sol.longestCommonSubstring(s1, s2);
    cout << "longest common substring is " << lcs_cnt << endl;
    return 0;
}
