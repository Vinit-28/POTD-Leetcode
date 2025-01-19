// Problem Link : https://leetcode.com/problems/trapping-rain-water-ii/description/


// Solution //
class Solution {
private:
    int dirRow[4] = {1,-1,0,0};
    int dirCol[4] = {0,0,1,-1};

    bool isValid(int m, int n, int i, int j){
        return !(i<0 || j<0 || i>=m || j>=n);
    }
public:
    int trapRainWater(vector<vector<int>>& hm) {
        int m = hm.size();
        int n = hm[0].size();
        int waterCollected = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> visited(m*n, false);
        // Inserting all the boundary cells in the PQ, as these would become the walls //
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if( i==0 || i==m-1 || j==0 || j==n-1 ){
                    pq.push({hm[i][j], i*n+j});
                    visited[i*n+j] = true;
                }
            }
        }
        while( pq.empty()==false ){
            auto [val, cell] = pq.top();
            int row = cell/n, col = cell%n;
            pq.pop();
            for(int k=0; k<4; k++){
                int nextRow = row + dirRow[k];
                int nextCol = col + dirCol[k];
                int nextCell = nextRow*n+nextCol;
                if( isValid(m, n, nextRow, nextCol) && visited[nextCell]==false ){
                    waterCollected += max(0, (val-hm[nextRow][nextCol]));
                    pq.push({max(val, hm[nextRow][nextCol]), nextCell});
                    visited[nextCell] = true;
                }
            }
        }
        return waterCollected;
    }
};