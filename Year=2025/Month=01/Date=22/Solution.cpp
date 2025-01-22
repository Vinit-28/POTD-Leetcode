// Problem Link : https://leetcode.com/problems/map-of-highest-peak/description/


// Solution //
class Solution {
private:
    int dirRow[4] = {1,-1,0,0};
    int dirCol[4] = {0,0,1,-1};

    bool isValid(int m, int n, int i, int j){
        return !(i<0 || j<0 || i>=m || j>=n);
    }

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> mat(m, vector<int>(n, -1));
        queue<int> que;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if( isWater[i][j] ){
                    mat[i][j] = 0;
                    que.push(i*n+j);
                }
            }
        }
        while( que.empty()==false ){
            int size = que.size();
            while( size-- > 0 ){
                int cell = que.front(); que.pop();
                int row = cell/n, col = cell%n;
                int val = mat[row][col];
                for(int k=0; k<4; k++){
                    int nextRow = row + dirRow[k];
                    int nextCol = col + dirCol[k];
                    int nextCell = nextRow*n+nextCol;
                    if( isValid(m, n, nextRow, nextCol) && mat[nextRow][nextCol] == -1 ){
                        mat[nextRow][nextCol] = val+1;
                        que.push(nextCell);
                    }
                }
            }
        }
        return mat;
    }
};