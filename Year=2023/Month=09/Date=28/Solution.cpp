// Problem Link : https://leetcode.com/problems/sort-array-by-parity/description/


// Solution //
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        vector<int> ans(nums.size());
        for(auto &ele : nums){
            if( ele & 1 ){
                ans[j--] = ele;
            } else{
                ans[i++] = ele;
            }
        }
        return ans;
    }
};