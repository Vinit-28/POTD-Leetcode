// Problem Link : https://leetcode.com/problems/rearrange-array-elements-by-sign/description/


// Solution //
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int neg = 1, pos = 0;
        for(int i=0;i<n;i++){
            if( nums[i] >= 0 ){
                ans[pos] = nums[i];
                pos += 2;
            } else{
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return ans;
    }
};
