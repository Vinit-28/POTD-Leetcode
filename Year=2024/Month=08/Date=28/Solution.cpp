// Problem Link : https://leetcode.com/problems/count-sub-islands/description/


// Solution //
class Solution {
private:
    int dirR[4] = {1,-1,0,0};
    int dirC[4] = {0,0,1,-1};

    bool isValid(int m, int n, int i, int j){
        return !(i<0 || j<0 || i>=m || j>=n);
    }

public:
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int m = g1.size(), n = g1[0].size();
        int count = 0;
        // Marking every island of Grid1 //
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if( g1[i][j] == 1 ){
                    DFS1(g1, m, n, i, j);
                }
            }
        }
        // Finding the answer //
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if( g2[i][j] == 1 && DFS2(g2, m, n, i, j, g1) ){
                    count += 1;
                }
            }
        }
        return count;
    }

    void DFS1(vector<vector<int>> &g, int m, int n, int i, int j){
        g[i][j] = -1;
        for(int k=0; k<4; k++){
            int nr = i+dirR[k];
            int nc = j+dirC[k];
            if( isValid(m, n, nr, nc) && g[nr][nc] == 1 ){
                DFS1(g, m, n, nr, nc);
            }
        }
    }

    bool DFS2(vector<vector<int>> &g, int m, int n, int i, int j, vector<vector<int>> &g2){
        g[i][j] = -1;
        bool ans = g2[i][j]==-1;
        for(int k=0; k<4; k++){
            int nr = i+dirR[k];
            int nc = j+dirC[k];
            if( isValid(m, n, nr, nc) && g[nr][nc] == 1 ){
                ans &= DFS2(g, m, n, nr, nc, g2);
            }
        }
        return ans;
    }
};
