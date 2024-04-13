// Problem Link : https://leetcode.com/problems/maximal-rectangle/description/


// Solution //
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[m-1].size();
        int grid[m][n];
        int maxArea = 0;

        // Setting up the horizontal bar for every cell //
        for(int i=m-1;i>=0;i--){
            int idx = n;
            for(int j=n-1;j>=0;j--){
                if( matrix[i][j] == '0' ) idx = j;
                grid[i][j] = idx - j;
            }
        }
        // This time we already have the horizontal bar,
        // So just trying out every vertical for a cell to find
        // the maximum area.
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if( matrix[i][j] == '0' ) continue;
                int width = grid[i][j];
                int length = 1;
                for(int r=i; r<m; r++,length++){
                    width = min(grid[r][j], width);
                    if( width == 0 ) break;
                    int area = length * width;
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};