// Problem Link : https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/description/


// Solution //
class Solution {
public:
    int dp[51][101][51]; // dp[n+1][m+1][k+1] //
    long MOD = 1e9+7;

    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(n, m, k, 0);
    }

    int solve(int n, int m, int k, int maxSoFar){
        if( k < 0 ){
            return 0;
        } else if( n == 0 ){
            return k==0;
        } else if( dp[n][maxSoFar][k] == -1 ){
            int ans = 0;
            for(int i=1;i<=m;i++){
                if( i <= maxSoFar ){
                    ans = (ans + solve(n-1, m, k, maxSoFar)) % MOD;
                } else{
                    ans = (ans + solve(n-1, m, k-1, i)) % MOD;
                }
            }
            dp[n][maxSoFar][k] = ans;
        }
        return dp[n][maxSoFar][k];
    }
};