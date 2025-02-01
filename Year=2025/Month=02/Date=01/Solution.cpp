// Problem Link : https://leetcode.com/problems/special-array-i/description/


// Solution //
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for(int idx=1; idx<n; idx++){
            int curr = nums[idx]&1;
            int prev = nums[idx-1]&1;
            if( curr==prev ) return false;
        }
        return true;
    }
};