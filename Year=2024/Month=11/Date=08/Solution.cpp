// Problem Link : https://leetcode.com/problems/maximum-xor-for-each-query/description/


// Solution //
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int mb) {
        int xorValue = 0;
        int n = nums.size();
        vector<int> ans(n);
        for(auto &ele : nums) xorValue ^= ele;
        for(int i=0; i<n; i++){
            int k = 0;
            for(int bitIdx=mb-1; bitIdx>=0; bitIdx--){
                int bit = (xorValue>>bitIdx)&1;
                if( bit==0 ) k += (1<<bitIdx);
            }
            ans[i] = k;
            xorValue ^= nums[n-i-1];
        }
        return ans;
    }
};