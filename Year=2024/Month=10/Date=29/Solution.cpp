// Problem Link : https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/


// Solution //
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        int ans = 0;
        memset(dp, 0, sizeof(dp));
        // Base Case //
        for(int i=0; i<m; i++) dp[i][n-1] = 1;
        // Filling the DP table //
        for(int j=n-2; j>=0; j--){
            for(int i=0; i<m; i++){
                if( i>0 && grid[i][j] < grid[i-1][j+1] ) dp[i][j] = max(dp[i][j], dp[i-1][j+1]);
                if( grid[i][j] < grid[i][j+1] ) dp[i][j] = max(dp[i][j], dp[i][j+1]);
                if( i<m-1 && grid[i][j] < grid[i+1][j+1] ) dp[i][j] = max(dp[i][j], dp[i+1][j+1]);
                dp[i][j] += 1;
                ans = j==0? max(ans, dp[i][j]) : ans;
            }
        }
        return max(ans-1, 0);
    }
};