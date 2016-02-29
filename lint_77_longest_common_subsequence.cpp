#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
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
                if(A[i-1] == B[j-1])
                    array[i][j] = array[i-1][j-1] + 1;
                else
                    array[i][j] = max(array[i-1][j], array[i][j-1]);
            }
        lcs_cnt = array[tb_len-1][tb_len-1];
        return lcs_cnt;
    }
};

int main(int argc, char* argv[]){
    string s1 = "guurdbaxypvwotateuursrhqnzqeqk";//"ABCD";//"ABCBDAB";
    string s2 = "qktmyfzeyelbckekldbbhrgbnpzqwo";//"EACB";//"BDCABA";
    Solution sol;
    int lcs_cnt = sol.longestCommonSubsequence(s1, s2);
    cout << "longest common subsequence is " << lcs_cnt << endl;
    return 0;
}
