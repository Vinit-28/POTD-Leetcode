// Problem Link : https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/


// Solution //
class Solution {
private:
    int dirRow[4] = {1, -1, 0, 0};
    int dirCol[4] = {0, 0, 1, -1};

    bool isValid(int m, int n, int i, int j){
        return !(i<0 || j<0 || i>=m || j>=n);
    }

public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int qSize = queries.size();
        vector<int> ans(qSize);
        vector<pair<int,int>> qArr;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for(int idx=0; idx<qSize; idx++){
            qArr.push_back({queries[idx], idx});
        }
        sort(qArr.begin(), qArr.end());
        int qIdx = 0;
        int cells = 0;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        while( qIdx < qSize ){
            if( pq.empty() || qArr[qIdx].first <= pq.top()[0] ){
                ans[qArr[qIdx++].second] = cells;
            } else{
                auto v = pq.top(); pq.pop();
                int ele = v[0], row = v[1], col = v[2];
                cells += 1;
                for(int k=0; k<4; k++){
                    int nextRow = row + dirRow[k];
                    int nextCol = col + dirCol[k];
                    if( isValid(m, n, nextRow, nextCol) && !visited[nextRow][nextCol] ){
                        visited[nextRow][nextCol] = true;
                        pq.push({grid[nextRow][nextCol], nextRow, nextCol});
                    }
                }
            }
        } 
        return ans;
    }
};