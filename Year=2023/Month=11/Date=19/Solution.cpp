// Problem Link : https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/


// Solution //
class Solution {
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        for(int i=n-1;i>0;i--){
            if( nums[i] != nums[i-1] ){
                ans += (n-i);
            }
        }
        return ans;
    }
};