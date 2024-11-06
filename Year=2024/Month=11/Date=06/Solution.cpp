// Problem Link : https://leetcode.com/problems/find-if-array-can-be-sorted/description/


// Solution //
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;i++){
            int ibits = __builtin_popcount(nums[i]);
            for(int j=0;j<i;j++){
                if( nums[i] < nums[j] && __builtin_popcount(nums[j]) != ibits ){
                    return false;
                }
            }
        }
        return true;
    }
};