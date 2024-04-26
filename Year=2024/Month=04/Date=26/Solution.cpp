// Problem Link : https://leetcode.com/problems/minimum-falling-path-sum-ii/description/


// Solution //
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int minIdx1=-1, minIdx2=-1; // Two min elements of next row //

        for(int row=n-1; row>=0; row--){
            int newMinIdx1=-1, newMinIdx2=-1; // Two min elements of current row //
            for(int col=0; col<n; col++){
                // Can't choose the first minimum of next row //
                if( row < n-1 ){
                    if( col == minIdx1 ){
                        grid[row][col] += grid[row+1][minIdx2];
                    } else{
                        grid[row][col] += grid[row+1][minIdx1];
                    }
                }
                // Updating the first & second minimum of current row //
                if( newMinIdx1==-1 || grid[row][newMinIdx1] > grid[row][col] ){
                    newMinIdx2 = newMinIdx1;
                    newMinIdx1 = col;
                } else if( newMinIdx2==-1 || grid[row][newMinIdx2] > grid[row][col] ){
                    newMinIdx2 = col;
                }
            }
            minIdx1 = newMinIdx1;
            minIdx2 = newMinIdx2;
        }
        return grid[0][minIdx1];
    }
};
