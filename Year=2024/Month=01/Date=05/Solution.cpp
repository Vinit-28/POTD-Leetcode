// Problem Link : https://leetcode.com/problems/longest-increasing-subsequence/description/


// Solution //
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        int dp[n];
        for(int i=n-1;i>=0;i--){
            dp[i] = 1;
            for(int j=n-1;j>i;j--){
                if( nums[i] < nums[j] ){
                    dp[i] = max(dp[i], (1 + dp[j]));
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};