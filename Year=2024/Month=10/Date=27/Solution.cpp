// Problem Link : https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/


// Solution //
class Solution {
public:
    int countSquares(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        int dp[m][n];
        // Base Cases //
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if( i == 0 || j == 0 ) dp[i][j] = mat[i][j];
                else dp[i][j] = 0;
            }
        }
        // Calculating the values //
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if( mat[i][j] == 0 ) continue;
                int top = dp[i-1][j];
                int left = dp[i][j-1];
                int topLeft = dp[i-1][j-1];
                dp[i][j] = 1 + min({top, left, topLeft});
            }
        }
        int count = 0;
        for(int i=0; i<m; i++) count += accumulate(dp[i], dp[i]+n, 0);
        return count;
    }
};