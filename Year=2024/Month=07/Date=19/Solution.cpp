// Problem Link : https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/


// Solution //
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> rowMin(m, INT_MAX), colMax(n, INT_MIN);
        vector<int> ans;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                rowMin[i] = min(rowMin[i], mat[i][j]);
                colMax[j] = max(colMax[j], mat[i][j]);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if( mat[i][j] == rowMin[i] && mat[i][j] == colMax[j] ){
                    ans.push_back(mat[i][j]);
                }
            }
        }
        return ans;
    }
};