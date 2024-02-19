// Problem Link : https://leetcode.com/problems/power-of-two/description/


// Solution //
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if( n == 0 ) return false;
        long num = n;
        return (num&(num-1))==0;
    }
};
