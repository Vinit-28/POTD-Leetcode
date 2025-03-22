// Problem Link : https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/


// Solution //
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0;
        int n = nums.size();
        for(int idx=0; idx<n; idx++){
            if( nums[idx] == 0 ){
                if( idx+2 >= n ) return -1;
                nums[idx] = 1;
                nums[idx+1] = !nums[idx+1];
                nums[idx+2] = !nums[idx+2];
                ops += 1;
            }
        }
        return ops;
    }
};