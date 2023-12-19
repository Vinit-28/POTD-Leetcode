// Problem Link : https://leetcode.com/problems/image-smoother/description/


// Solution //
class Solution {
public:
    bool isCellValid(int &m, int &n, int &i, int &j){
        return !(i<0 || j<0 || i>=m || j>=n);
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[m-1].size();
        int dirR[] = {0, 0, -1, 1, -1, -1, 1, 1};
        int dirC[] = {-1, 1, 0, 0, -1, 1, 1, -1};
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int validCells = 1, sum = img[i][j];
                for(int k=0;k<8;k++){
                    int r = dirR[k] + i, c = dirC[k] + j;
                    if( isCellValid(m, n, r, c) ){
                        sum += img[r][c];
                        validCells += 1;
                    }
                }
                ans[i][j] = sum / validCells;
            }
        }
        return ans;
    }
};