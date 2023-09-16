// Problem Link : https://leetcode.com/problems/path-with-minimum-effort/description/


// Solution //
class Solution {
public:
    int dirR[4] = {1,-1,0,0}, dirC[4] = {0,0,1,-1};

    bool isCellValid(int i, int j, int &r, int &c){
        return !(i<0 || j<0 || i>=r || j>=c);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();
        bool isVisited[r][c]; memset(isVisited, 0, sizeof(isVisited));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap; // { {maxDiffTill, i, j} } //
        
        // Main Logic //
        minHeap.push({0, 0, 0});
        while( minHeap.empty() == false ){
            auto v = minHeap.top(); minHeap.pop();
            int maxDiffTill = v[0], i = v[1], j = v[2];
            if( isVisited[i][j] ){
                continue;
            }
            isVisited[i][j] = true;
            if( i==r-1 && j == c-1 ){
                return maxDiffTill;
            } else{
                for(int k=0;k<4;k++){
                    int x = dirR[k] + i, y = dirC[k] + j;
                    if( isCellValid(x, y, r, c) && !isVisited[x][y] ){
                        int currDiff = abs(heights[i][j] - heights[x][y]);
                        minHeap.push({max(maxDiffTill, currDiff), x, y});
                    }
                }
            }
        }
        return 0;
    }
};