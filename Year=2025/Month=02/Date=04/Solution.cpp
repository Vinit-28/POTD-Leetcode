// Problem Link : https://leetcode.com/problems/maximum-ascending-subarray-sum/description/


// Solution //
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int maxSum = nums[0];
        int n = nums.size();
        for(int idx=1; idx<n; idx++){
            if( nums[idx] <= nums[idx-1] ) sum = 0;
            sum += nums[idx];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};