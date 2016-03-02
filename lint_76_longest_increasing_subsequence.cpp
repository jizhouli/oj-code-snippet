#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        return lis_opt(nums);
    }

    int lis(vector<int> nums){
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

    int lis_opt(vector<int> nums) {
        int lis_cnt = 0;
        if (!nums.size())
            return lis_cnt;

        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = nums[0];
        lis_cnt = 1;

        for(int i=1; i<nums.size(); i++){
            int j = 0;
            while(/*j<nums.size() && */dp[j]<=nums[i])
                j++;
            dp[j] = nums[i];
            lis_cnt = max(j+1, lis_cnt);
            //cout << j << " "<< lis_cnt << endl;
        }
        return lis_cnt;
    }
};

int main(int argc, char* argv[]){
    int _nums[] = {4,2,4,5,3,7};
    //int _nums[] = {1,1,1,1};

    vector<int> nums(_nums, _nums+sizeof(_nums)/sizeof(_nums[0]));

    Solution sol;
    int lis_cnt = sol.longestIncreasingSubsequence(nums);
    cout << "longest increasing subsequence is " << lis_cnt << endl;
    return 0;
}
