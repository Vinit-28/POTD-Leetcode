// Problem Link : https://leetcode.com/problems/unique-paths/


// Solution //
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n]; memset(dp, 0, sizeof(dp));
        dp[m-1][n-1] = 1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if( i == m-1 && j == n-1 ){
                    dp[i][j] = 1;
                } else if( i== m-1 ){
                    dp[i][j] = dp[i][j+1];
                } else if( j== n-1 ){
                    dp[i][j] = dp[i+1][j];
                } else{
                    dp[i][j] = dp[i][j+1] + dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};