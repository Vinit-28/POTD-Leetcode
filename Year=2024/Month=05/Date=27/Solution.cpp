// Problem Link : https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/


// Solution //
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++){
            int count = (n- i);
            if( count <= nums[i] && (i==0 || nums[i-1] < count) ){
                return count;
            }
        }
        return -1;
    }
};