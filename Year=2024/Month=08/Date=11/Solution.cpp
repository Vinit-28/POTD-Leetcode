// Problem Link : https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/



// Disjoint Set Union //
class Solution {
private:
    int dirR[4] = {1,-1,0,0};
    int dirC[4] = {0,0,1,-1};

    bool isValid(int m, int n, int i, int j){
        return !(i<0 || j<0 || i>=m || j>=n);
    }

public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // If grid already has multiple components //
        if( getComponents(m, n, grid) != 1 ) return 0;
        // Trying to do in just 1 operation(if possible) //
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if( grid[i][j] == 1 ){
                    grid[i][j] = 0;
                    int components = getComponents(m, n, grid);
                    grid[i][j] = 1;
                    if( components != 1 ){
                        cout<<i<<","<<j<<" :: "<<components<<endl;
                        return 1;
                    } 
                }
            }
        }
        // We will always be able to make the answer in 2 operations //
        return 2;
    }

    int getComponents(int m, int n, vector<vector<int>> &grid){
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int components = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if( grid[i][j] == 1 && !visited[i][j] ){
                    components += 1;
                    DFS(m, n, i, j, grid, visited);
                }
            }
        }
        return components;
    }

    void DFS(int m, int n, int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited){
        visited[i][j] = true;
        for(int k=0; k<4; k++){
            int r = i + dirR[k];
            int c = j + dirC[k];
            if( isValid(m, n, r, c) && grid[r][c] == 1 && visited[r][c] == false ){
                DFS(m, n, r, c, grid, visited);
            }
        }
    }
};