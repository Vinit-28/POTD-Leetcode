// Problem Link : https://leetcode.com/problems/n-th-tribonacci-number/description/


// Solution //
class Solution {
public:
    int tribonacci(int n) {
        if( n<=1 ) return n;
        if( n==2 ) return 1;
        int a=0, b=1, c=1;
        for(int t=3; t<=n; t++){
            int val = a + b + c;
            a = b, b = c, c = val;
        }
        return c;
    }
};