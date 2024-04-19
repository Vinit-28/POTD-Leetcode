// Problem Link : https://leetcode.com/problems/number-of-islands/description/


// Solution //
class Solution {
public:
    
    int dirRow[4] = {1, -1, 0, 0};
    int dirCol[4] = {0, 0, 1, -1};
    
    bool isValid(int i, int j, int &m, int &n){
        return !(i<0 || i>=m || j<0 || j>=n);
    }
    
    void DFS(vector<vector<char>>& grid, int &i, int &j, int &m, int &n){
        grid[i][j] = 'V';
        for(int pos=0;pos<4;pos++){
            
            int r = dirRow[pos] + i, c = dirCol[pos] + j;
            if( isValid(r, c, m, n) && grid[r][c]=='1' ){
                DFS(grid, r, c, m, n);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size(), n = grid[0].size(), islands = 0;
    
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if( grid[i][j]=='1' ){
                    DFS(grid, i, j, m, n);
                    islands += 1;
                }

        return islands;
    }
};
