// Problem Link : https://leetcode.com/problems/island-perimeter/description/


// Solution //
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if( grid[i][j] == 1 ){
                    ans += getZeroSides(grid, m, n, i, j);
                }
            }
        }
        return ans;
    }

    int getZeroSides(vector<vector<int>>& grid, int m, int n, int i, int j){
        int dirR[] = {1,-1,0,0};
        int dirC[] = {0,0,1,-1};
        int count = 0;
        for(int k=0; k<4; k++){
            int r = i + dirR[k];
            int c = j + dirC[k];
            if( !isValid(m, n, r, c) || grid[r][c] == 0 ){
                count += 1;
            }
        }
        return count;
    }

    bool isValid(int m, int n, int i, int j){
        return !(i<0 || j<0 || i>=m || j>=n);
    }
};