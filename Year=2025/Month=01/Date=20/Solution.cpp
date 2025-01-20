// Problem Link : https://leetcode.com/problems/first-completely-painted-row-or-column/description/


// Solution //
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[m-1].size();
        int size = arr.size();
        vector<int> rowFill(m, 0), colFill(n, 0);
        unordered_map<int, int> mpp;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int cell = i*n+j;
                mpp[mat[i][j]] = cell;
            }
        } 
        for(int idx=0; idx<size; idx++){
            int val = arr[idx];
            int cell = mpp[val];
            int row = cell/n, col = cell%n;
            if( ++rowFill[row] == n ) return idx;
            if( ++colFill[col] == m ) return idx;
        }
        return -1;
    }
};