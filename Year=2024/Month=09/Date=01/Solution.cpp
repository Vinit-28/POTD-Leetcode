// Problem Link : https://leetcode.com/problems/convert-1d-array-into-2d-array/description/


// Solution //
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        if( size != (m*n) ) return {};
        vector<vector<int>> mat(m, vector<int>(n));
        for(int idx=0; idx<size; idx++){
            int r = idx/n;
            int c = idx%n;
            mat[r][c] = original[idx];
        }
        return mat;
    }
};