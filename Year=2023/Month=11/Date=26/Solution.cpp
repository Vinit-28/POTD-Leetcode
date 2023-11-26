// Problem Link : https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/


// Solution //
class Solution {
public:
    int largestSubmatrix(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        int ans = 0;
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if( mat[i][j] ){
                    mat[i][j] += mat[i-1][j];
                }
            }
        }
        for(auto &row : mat){
            sort(row.begin(), row.end(), greater<int>());
            for(int j=0;j<n;j++){
                ans = max(ans, (row[j]*(j+1)));
            }
        }
        return ans;
    }
};