// Problem Link : https://leetcode.com/problems/count-servers-that-communicate/description/


// Solution //
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int rows[m], cols[n];
        int count = 0;
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if( grid[i][j] == 1 ) rows[i]+=1, cols[j]+=1;
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if( grid[i][j] == 1 ) count += (rows[i]>1 || cols[j]>1);
            }
        }
        return count;
    }
};