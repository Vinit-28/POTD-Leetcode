// Problem Link : https://leetcode.com/problems/longest-nice-subarray/description/


// Solution //
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> latestSetBitIdx(32, -1);
        int n = nums.size();
        int longestSize = 1;
        int start = -1;
        for(int idx=0; idx<n; idx++){
            for(int bitIdx=0; bitIdx<31; bitIdx++){
                int bit = (nums[idx]>>bitIdx)&1;
                if( bit ){
                    start = max(start, latestSetBitIdx[bitIdx]);
                    latestSetBitIdx[bitIdx] = idx;
                }
            }
            int size = idx - start;
            longestSize = max(longestSize, size);
        }
        return longestSize;
    }
};