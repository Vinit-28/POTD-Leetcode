// Problem Link : https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/


// Solution //
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxInc = 1;
        int maxDec = 1;
        int inc = 1, dec = 1;
        int n = nums.size();
        for(int idx=1; idx<n; idx++){
            if( nums[idx-1] >= nums[idx] ) inc=0;
            if( nums[idx-1] <= nums[idx] ) dec=0;
            inc += 1;
            dec += 1;
            maxInc = max(maxInc, inc);
            maxDec = max(maxDec, dec);
        }
        return max(maxInc, maxDec);
    }
};