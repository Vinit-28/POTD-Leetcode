// Problem Link : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/


// Solution //
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 1;
        int n = nums.size();
        for(int idx=1; idx<n; idx++){
            count += (nums[idx] < nums[idx-1]);
        }
        count += (nums[0] < nums[n-1]);
        return count <= 2;
    }
};