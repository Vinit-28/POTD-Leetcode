// Problem Link : https://leetcode.com/problems/score-after-flipping-matrix/description/


// Solution //
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int sum = 0;
        // Toggle the rows starting with 0 //
        for(int i=0; i<m; i++){
            if( grid[i][0] == 0 ){
                toggleRow(grid[i]);
            }
        }
        // Toggle the columns having count of 0s more than 1s //
        for(int j=0; j<n; j++){
            int zero = 0;
            for(int i=0; i<m; i++){
                zero += grid[i][j]==0;
            }
            if( (m - zero) < zero ){
                toggleColumn(grid, m, j);
            }
        }
        // Calculate the Sum //
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if( grid[i][j] == 1 ){
                    sum += (1 << (n-j-1));
                }
            }
        }
        return sum;
    }

    void toggleRow(vector<int> &row){
        for(auto &val : row){
            val = !val;
        }
    }

    void toggleColumn(vector<vector<int>> &grid, int &m, int col){
        for(int r=0; r<m; r++){
            auto &val = grid[r][col];
            val = !val;
        }
    }
};