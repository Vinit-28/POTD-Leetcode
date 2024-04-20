// Problem Link : https://leetcode.com/problems/find-all-groups-of-farmland/description/


// Solution //
class Solution {
public:
    int dirR[4] = {1,-1,0,0};
    int dirC[4] = {0,0,1,-1};

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> farmlands;
        int m = land.size(), n = land[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if( land[i][j] == 1 ){
                    vector<int> farmland = {i,j,i,j};
                    DFS(land, m, n, i, j, farmland);
                    farmlands.push_back(farmland);
                }
            }
        }
        return farmlands;
    }

    void DFS(vector<vector<int>> &land, int &m, int &n, int i, int j, vector<int> &farmland){
        // Updating the Top-Left & Bottom-Right Corners of the Farmland //
        farmland[0] = min(farmland[0], i);
        farmland[1] = min(farmland[1], j);
        farmland[2] = max(farmland[2], i);
        farmland[3] = max(farmland[3], j);
        // Marking the cell as visited //
        land[i][j] = -1;
        // Moving to adjacent cells //
        for(int k=0; k<4; k++){
            int r = i + dirR[k];
            int c = j + dirC[k];
            if( isCellValid(m, n, r, c) && land[r][c]==1 ){
                DFS(land, m, n, r, c, farmland);
            }
        }
    }

    bool isCellValid(int &m, int &n, int &i, int &j){
        return !(i<0 || j<0 || i>=m || j>=n);
    }
};