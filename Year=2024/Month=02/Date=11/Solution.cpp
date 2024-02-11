// Problem Link : https://leetcode.com/problems/cherry-pickup-ii/description/


// Solution //
class Solution {
public:
    int m, n;
    int dp[70][70][70];
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        m = grid.size(), n = grid[0].size();
        return helper(grid, 0, 0, n-1);
    }

    int helper(vector<vector<int>>& grid, int i, int j, int k){
        if( i>=m || j<0 || j>=n || k<0 || k>=n ){
            return 0;
        } else if( dp[i][j][k] == -1 ){
            int r1, r2;
            if( j==k ){
                r1 = grid[i][j], r2 = 0;
            } else{
                r1 = grid[i][j], r2 = grid[i][k];
            }
            int left = 0, mid = 0, right = 0;
            // Robot1 -> -1 //
            left = max(left, helper(grid, i+1, j-1, k-1));
            left = max(left, helper(grid, i+1, j-1, k));
            left = max(left, helper(grid, i+1, j-1, k+1));

            // Robot1 -> 0 //
            mid = max(mid, helper(grid, i+1, j, k-1));
            mid = max(mid, helper(grid, i+1, j, k));
            mid = max(mid, helper(grid, i+1, j, k+1));

            // Robot1 -> 1 //
            right = max(right, helper(grid, i+1, j+1, k-1));
            right = max(right, helper(grid, i+1, j+1, k));
            right = max(right, helper(grid, i+1, j+1, k+1));

            dp[i][j][k] = max({left, mid, right})+r1+r2;
        }
        return dp[i][j][k];
    }

    // bool isValid()
};