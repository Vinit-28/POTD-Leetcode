// Problem Link : https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/


// Solution //
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<long, int> dp[n];
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                long diff = long(nums[i]) - long(nums[j]);
                if( diff <= INT_MIN || diff >= INT_MAX ) continue;
                ans += dp[j][diff];
                dp[i][diff] += (dp[j][diff]+1);
            }
        }
        return ans;
    }
};