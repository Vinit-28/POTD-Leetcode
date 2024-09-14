// Problem Link : https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/


// Solution //
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(begin(nums), end(nums));
        int count = 0;
        int maxCount = 0;
        for(auto &ele : nums){
            count = (ele==maxi? count+1 : 0);
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};