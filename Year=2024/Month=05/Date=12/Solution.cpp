// Problem Link : https://leetcode.com/problems/largest-local-values-in-a-matrix/description/


// Solution //
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2, -1));
        for(int i=0; i<n-2; i++){
            for(int j=0; j<n-2; j++){
                ans[i][j] = getMaxOfMatrix(grid, i, j);
            }
        }
        return ans;
    }

    int getMaxOfMatrix(vector<vector<int>>& grid, int i, int j){
        int maxi = grid[i][j];
        for(int r=i; (r-i)<3; r++){
            for(int c=j; (c-j)<3; c++){
                maxi = max(maxi, grid[r][c]);
            }
        }
        return maxi;
    }
};
