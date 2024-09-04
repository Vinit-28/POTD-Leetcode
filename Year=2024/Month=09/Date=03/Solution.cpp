// Problem Link : https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/


// Solution //
class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for(auto &ch : s) sum += helper(ch-'a'+1, 1);
        return helper(sum, k-1);
    }

    int helper(int n, int k){
        if( k == 0 || n <= 9 ) return n;
        int sum = 0;
        while( n>0 ) sum += (n%10), n /= 10;
        return helper(sum, k-1);
    }
};