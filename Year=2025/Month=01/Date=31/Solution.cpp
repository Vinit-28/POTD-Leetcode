// Problem Link : https://leetcode.com/problems/making-a-large-island/description/


// Solution //
class DSU{
public:
    vector<int> parents;
    vector<int> componentSize;
    DSU(int n){
        parents = vector<int>(n, -1);
        componentSize = vector<int>(n, 1);
    }

    int findParent(int node){
        if( parents[node]==-1 ){
            return node;
        }
        return parents[node] = findParent(parents[node]);
    }

    void _union(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if( pu != pv ){
            parents[pv] = pu;
            componentSize[pu] += componentSize[pv];
        }
    }

    int getComponentSize(int node){
        int parent = findParent(node);
        return componentSize[parent];
    }
};

class Solution {
private:
    int dirRow[4] = {-1,1,0,0};
    int dirCol[4] = {0,0,1,-1};
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[m-1].size();
        int cells = m*n;
        int maxSize = 0;
        DSU dsu(cells);

        // Connecting the components //
        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                if( grid[row][col] == 0 ) continue;
                int cell = getCell(n, row, col);
                for(int dir=0; dir<4; dir++){
                    int nextRow = row + dirRow[dir];
                    int nextCol = col + dirCol[dir];
                    int nextCell = getCell(n, nextRow, nextCol);
                    if( isCellValid(m, n, nextRow, nextCol) && grid[nextRow][nextCol]==1 ){
                        dsu._union(cell, nextCell);
                    }
                }
                maxSize = max(maxSize, dsu.getComponentSize(cell));
            }
        }
        // Finding the best answer //
        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                if( grid[row][col] == 1 ) continue;
                set<int> parents;
                for(int dir=0; dir<4; dir++){
                    int nextRow = row + dirRow[dir];
                    int nextCol = col + dirCol[dir];
                    int nextCell = getCell(n, nextRow, nextCol);
                    if( isCellValid(m, n, nextRow, nextCol) && grid[nextRow][nextCol]==1 ){
                        int parent = dsu.findParent(nextCell);
                        parents.insert(parent);
                    }
                }
                int size = 1;
                for(int parent: parents){
                    size += dsu.getComponentSize(parent);
                }
                maxSize = max(maxSize, size);
            }
        }
        return maxSize;
    }

private:
    bool isCellValid(int &m, int &n, int &row, int &col){
        return !(row<0 || col<0 || row>=m || col>=n);
    }

    int getCell(int n, int row, int col){
        return row*n+col;
    }

    pair<int,int> getRC(int n, int cell){
        return {cell/n, cell%n};
    }
};