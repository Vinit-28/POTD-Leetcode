// Problem Link : https://leetcode.com/problems/integer-break/description/


// Solution //
class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        dp[0] = dp[1] = 1;
        return max(solve(n, n-1, dp), 1);
    }

    int solve(int n, int k, int dp[]){
        if( dp[n] == -1 ){
            dp[n] = 0;
            for(int i=2;i<=k;i++){
                dp[n] = max(dp[n], i * solve(n-i, n-i, dp));
            }
        }
        return dp[n];
    }
};