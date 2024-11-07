// Problem Link : https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/description/


// Solution //
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxGroupSize = 0;
        for(int bitIdx=0; bitIdx<31; bitIdx++){
            int setBits = 0;
            for(auto &ele : candidates){
                int bit = (ele>>bitIdx)&1;
                setBits += bit;
            }
            maxGroupSize = max(maxGroupSize, setBits);
        }
        return maxGroupSize;
    }
};