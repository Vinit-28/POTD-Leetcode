// Problem Link : https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/


// Solution //
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[m-1].size();
        int ans = 0;
        for(int i=0;i<m;i++){
            int oneCount = 0;
            bool flag = false;
            for(int j=0;j<n;j++){
                if( mat[i][j] ){
                    oneCount += 1;
                    flag = flag | isValid(mat, j, m);
                }
            }
            ans += oneCount==1 && flag? 1 : 0;
        }
        return ans;
    }

    bool isValid(vector<vector<int>>& mat, int colIdx, int &m){
        int count = 0;
        for(int i=0;i<m;i++){
            count += mat[i][colIdx];
        }
        return count==1;
    }
};