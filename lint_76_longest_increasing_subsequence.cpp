#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        int lis_cnt = 0;
        vector<int> dp(nums.size(), 1);

        for(int i=0; i<nums.size(); i++)
            for(int j=0;j<i;j++)
                if((nums[j]<=nums[i]) && (dp[i]<(dp[j]+1)))
                    dp[i] = dp[j]+1;

        for(int i=0; i<nums.size(); i++)
            if(lis_cnt<dp[i])
                lis_cnt = dp[i];
        return lis_cnt;
    }
};

int main(int argc, char* argv[]){
    int _nums[] = {4,2,4,5,3,7};

    vector<int> nums(_nums, _nums+sizeof(_nums)/sizeof(_nums[0]));

    Solution sol;
    int lis_cnt = sol.longestIncreasingSubsequence(nums);
    cout << "longest increasing subsequence is " << lis_cnt << endl;
    return 0;
}
