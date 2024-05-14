// Problem Link : https://leetcode.com/problems/path-with-maximum-gold/description/


// Solution //
class Solution {
public:
    int dirR[4] = {1,-1,0,0};
    int dirC[4] = {0,0,1,-1};
    int m,n;
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int maxi = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if( grid[i][j] > 0 ){
                    maxi = max(maxi, DFS(grid, i, j));
                }
            }
        }
        return maxi;
    }

    int DFS(vector<vector<int>> &grid, int i, int j){
        int value = grid[i][j];
        grid[i][j] = -1;
        int maxi = 0;
        for(int k=0; k<4; k++){
            int r = i + dirR[k], c = j + dirC[k];
            if( isValid(r, c) && grid[r][c] > 0 ){
                maxi = max(maxi, DFS(grid, r, c));
            }
        }
        grid[i][j] = value;
        return value + maxi;
    }

    bool isValid(int i, int j){
        return !(i<0 || j<0 || i>=m || j>=n);
    }
};