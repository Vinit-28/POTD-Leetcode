// Problem Link : https://leetcode.com/problems/climbing-stairs/description/


// Solution //
class Solution {
public:
    int climbStairs(int n) {
        if( n == 1 || n==2 || n==3 ) return n;
        int nxt1 = 2, nxt2 = 1;
        for(int i=n-2;i>0;i--){
            int curr = nxt1 + nxt2;
            nxt2 = nxt1, nxt1 = curr;
        }
        return nxt1;
    }
};