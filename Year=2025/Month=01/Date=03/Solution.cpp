// Problem Link : https://leetcode.com/problems/number-of-ways-to-split-array/description/


// Solution //
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long totalSum = accumulate(begin(nums), end(nums), (long)0);
        long prefixSum = 0;
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n-1; i++){
            prefixSum += nums[i];
            count += (prefixSum >= (totalSum - prefixSum));
        }
        return count;
    }
};