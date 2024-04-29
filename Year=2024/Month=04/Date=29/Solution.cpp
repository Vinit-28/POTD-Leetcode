// Problem Link : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/


// Solution //
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ops = 0;
        for(int bitIdx=0; bitIdx<=31; bitIdx++){
            int setBits = 0;
            int bitReq = (k >> bitIdx)&1;
            for(auto &ele : nums){
                int bit = (ele >> bitIdx)&1;
                setBits += bit;
            }
            if( bitReq == 1 && !(setBits&1) ) ops += 1;
            else if( bitReq == 0 && setBits&1 ) ops += 1;
        }
        return ops;
    }
};
