// Problem Link : https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/


// Solution //
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        int i=0, j=0;
        vector<vector<int>> mat(m, vector<int>(n, 0));
        while( i<m && j<n ){
            int sum = min(rowSum[i], colSum[j]);
            mat[i][j] += sum;
            colSum[j] -= sum;
            rowSum[i] -= sum;
            if( colSum[j] == 0 ){
                j += 1;
            } else{
                i += 1;
            }
        }
        return mat;
    }
};