// Problem Link : https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/


// Solution //
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int combinations = (1<<n)-1;
        int totalXorSum = 0;
        for(int comb=0; comb<=combinations; comb++){
            int xorValue = 0;
            for(int bitIdx=0; bitIdx<n; bitIdx++){
                int bit = (comb>>bitIdx)&1;
                if( bit == 1 ){
                    xorValue ^= nums[bitIdx];
                }
            }
            totalXorSum += xorValue;
        }
        return totalXorSum;
    }
};