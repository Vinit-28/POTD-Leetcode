// Problem Link : https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/


// Solution //
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = lower_bound(begin(nums), end(nums), 0) - begin(nums);
        int pos = nums.size() - (upper_bound(begin(nums), end(nums), 0) - begin(nums));
        return max(neg, pos);
    }
};