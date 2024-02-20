// Problem Link : https://leetcode.com/problems/missing-number/description/


// Solution //
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(auto &ele : nums) sum += ele;
        return ((n*(n+1)/2)-sum);
    }
};
