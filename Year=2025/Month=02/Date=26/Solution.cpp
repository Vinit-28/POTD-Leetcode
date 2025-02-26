// Problem Link : https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/


// Solution //
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int posSum = 0;
        int negSum = 0;
        int maxPosSum = 0;
        int maxNegSum = 0;
        for(auto &ele : nums){
            if( (posSum + ele) < ele ) posSum = 0;
            if( (negSum + ele) > ele ) negSum = 0;
            posSum += ele;
            negSum += ele;
            maxPosSum = max(maxPosSum, posSum);
            maxNegSum = min(maxNegSum, negSum);
        }
        return max(maxPosSum, abs(maxNegSum));
    }
};