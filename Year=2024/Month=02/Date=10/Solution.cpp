// Problem Link : https://leetcode.com/problems/palindromic-substrings/description/


// Solution //
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        bool dp[n][n]; memset(dp, false, sizeof(dp));
        for(int c=0;c<n;c++){
            for(int i=0,j=c;j<n;i++,j++){
                if( i==j ) dp[i][j] = true;
                else if( s[i] == s[j] ) dp[i][j] = ((i+1) > (j-1))? true : dp[i+1][j-1];
                count += dp[i][j];
            }
        }
        return count;
    }
};