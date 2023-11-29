// Problem Link : https://leetcode.com/problems/number-of-1-bits/description/


// Solution //
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c=0;
        for(int i=31;i>=0;i--)
            c += ((n>>i)&1);
        return c;
    }
};