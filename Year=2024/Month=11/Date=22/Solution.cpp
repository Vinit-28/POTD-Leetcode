// Problem Link : https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/


// Solution //
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<vector<int>, int> mpp;
        int m = matrix.size();
        int n = matrix[0].size();
        int maxRows = 0;
        for(int i=0; i<m; i++){
            vector<int> colsNeedsOps;
            for(int j=1; j<n; j++){
                if( matrix[i][j-1] != matrix[i][j] ){
                    colsNeedsOps.push_back(j);
                }
            }
            maxRows = max(maxRows, ++mpp[colsNeedsOps]);
        }
        return maxRows;
    }
};