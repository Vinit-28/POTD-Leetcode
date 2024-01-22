// Problem Link : https://leetcode.com/problems/house-robber/description/


// Solution //
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), inc, exc;;
        inc = nums[0], exc = 0;
        for(int i=1;i<n;i++){
            int newInc = nums[i] + exc;
            int newExc = max(inc, exc);
            inc = newInc, exc = newExc;
        }
        return max(inc, exc);
    }
};