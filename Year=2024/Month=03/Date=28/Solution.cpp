// Problem Link : https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/


// Solution //
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        int totalSize = nums.size();
        int maxLen = 1;
        int start = 0, end = 0;
        while( start < totalSize ){
            while( end < totalSize ){
                if( freqMap[nums[end]] == k ){
                    break;
                }
                freqMap[nums[end]] += 1;
                end += 1;
            }
            maxLen = max(maxLen, (end - start));
            freqMap[nums[start]] -= 1;
            start += 1;
        }
        return maxLen;
    }
};