// Problem Link : https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/description/



// Solution //
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        // Declaration //
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> diff(m, vector<int>(n));
        vector<int> rowOnes(m, 0), colOnes(n, 0);
        // Initialization //
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rowOnes[i] += grid[i][j];
                colOnes[j] += grid[i][j];
            }
        }
        // Main Logic //
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int onesRow = rowOnes[i], onesCol = colOnes[j];
                int zerosRow = m-rowOnes[i], zerosCol = n-colOnes[j];
                diff[i][j] = onesRow + onesCol - zerosRow - zerosCol;
            }
        }
        return diff;
    }
};