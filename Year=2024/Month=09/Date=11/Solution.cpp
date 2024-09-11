// Problem Link : https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/


// Solution //
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        for(int bitIdx=0; bitIdx<=30; bitIdx++){
            int a = (start>>bitIdx)&1;
            int b = (goal>>bitIdx)&1;
            ans += (a!=b);
        }
        return ans;
    }
};