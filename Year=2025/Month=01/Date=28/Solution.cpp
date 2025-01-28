// Problem Link : https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/


// Solution //
class Solution {
private:
    int dirRow[4] = {1,-1,0,0};
    int dirCol[4] = {0,0,1,-1};

    bool isCellValid(int &m, int &n, int &r, int &c){
        return !(r<0 || c<0 || r>=m || c>=n);
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[m-1].size();
        int maxFishes = 0;
        int cells = m*n;
        vector<bool> visited(cells, false);

        for(int cell=0; cell<cells; cell++){
            int row = cell/n;
            int col = cell%n;
            if( grid[row][col]>0 && !visited[cell] ){
                int fishes = countFishes(grid, visited, m, n, cell);
                maxFishes = max(maxFishes, fishes);
            }
        }
        return maxFishes;
    }

private:
    int countFishes(vector<vector<int>> &grid, vector<bool> &visited, int &m, int &n, int cell){
        int fishes = 0;
        queue<int> que;
        que.push(cell);
        visited[cell] = true;
        while( que.empty()==false ){
            int size = que.size();
            while( size-- > 0 ){
                int cell = que.front(); que.pop();
                int row = cell/n;
                int col = cell%n;
                fishes += grid[row][col];
                for(int k=0; k<4; k++){
                    int nextRow = row + dirRow[k];
                    int nextCol = col + dirCol[k];
                    int nextCell = nextRow*n+nextCol;
                    if( isCellValid(m, n, nextRow, nextCol) && !visited[nextCell] && grid[nextRow][nextCol]>0 ){
                        visited[nextCell] = true;
                        que.push(nextCell);
                    }
                }
            }
        }
        return fishes;
    }
};