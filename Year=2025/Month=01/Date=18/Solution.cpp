// Problem Link : https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/


// Solution //
class Solution {
private:
    int dirRow[5] = {0,0,0,1,-1};
    int dirCol[5] = {0,1,-1,0,0};

    bool isValid(int &m, int &n, int row, int col){
        return !(row<0 || col<0 || row>=m || col>=n);
    }

public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> costs(m, vector<int>(n, 1e9));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        costs[0][0] = 0;
        while( pq.empty()==false ){
            auto [cost, cell] = pq.top(); pq.pop();
            int row = cell/n, col = cell%n;
            if( row==m-1 && col==n-1 ){
                break;
            } else{
                for(int dir=1; dir<5; dir++){
                    int nextRow = row + dirRow[dir];
                    int nextCol = col + dirCol[dir];
                    int nextCost = cost + (dir!=grid[row][col]);
                    int nextCell = (nextRow*n)+nextCol;
                    if( isValid(m, n, nextRow, nextCol) && nextCost < costs[nextRow][nextCol] ){
                        costs[nextRow][nextCol] = nextCost;
                        pq.push({nextCost, nextCell});
                    }
                }
            }
        }
        return costs[m-1][n-1];
    }
};