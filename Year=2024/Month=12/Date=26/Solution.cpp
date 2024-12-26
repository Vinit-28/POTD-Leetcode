// Problem Link : https://leetcode.com/problems/target-sum/description/


// Solution //
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(begin(nums), end(nums), 0);
        int rem = totalSum - target;
        if( rem < 0 || rem&1 ) return 0;
        // some part of the remaining sum has to be added in the sum & other part of the 
        // remaining sum has to be decremented.
        // So actually half part fo the remaining sum has to be added & has to be reduced, so it should
        // be even.
        // Now I just need to find the number of subsets having sum = rem/2, so that the 
        // sum = totalSum - subsetSum will be nothing but my = target + rem/2
        int subsetSumTarget = rem/2;
        vector<int> dp(subsetSumTarget+1, 0);
        dp[0] = 1;
        for(int idx=0; idx<n; idx++){
            for(int sum=subsetSumTarget; sum>=0; sum--){
                dp[sum] += sum<nums[idx]? 0 : dp[sum - nums[idx]];
            }
        }
        return dp[subsetSumTarget];
    }
};