// Problem Link : https://leetcode.com/problems/longest-palindromic-substring/description/


// Solution //
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), start = 0, end = 0, maxLen = 1;
        bool dp[n][n];
        for(int i=0;i<n;i++){
            for(int r=0,c=i; c<n; r++,c++){
                if( r==c ){
                    dp[r][c] = true;
                } else if( s[r] == s[c] ){
                    int nr = r+1, pc = c-1;
                    if( nr >= pc || dp[nr][pc] ){
                        dp[r][c] = true;
                    } else{
                        dp[r][c] = false;
                    }
                } else{
                    dp[r][c] = false;
                }
                if( dp[r][c] && (c-r+1) > maxLen ){
                    start = r, end = c;
                    maxLen = (c-r+1);
                }
            }
        }
        return s.substr(start, end-start+1);
    }
};