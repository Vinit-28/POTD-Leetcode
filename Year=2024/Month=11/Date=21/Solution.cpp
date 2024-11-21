// Problem Link : https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/


// Solution //
class Solution {
private:
    int dirRow[4] = {1,-1,0,0};
    int dirCol[4] = {0,0,1,-1};
    
    bool isCellValid(int m, int n, int r, int c){
        return !(r<0 || c<0 || r>=m || c>=n);
    }
    
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        queue<int> q;
        int mat[m][n];
        /*
            Guard Cells: 1
            Gaurded Cells: -1
            Wall Cells: 2
            Unguarded Cells: 0
        */
        memset(mat, 0, sizeof(mat)); // Every cell as Unguarded cell //
        // Placing walls //
        for(auto &wall : walls){
            int r = wall[0], c = wall[1];
            mat[r][c] = 2;
        }
        // Placing guards //
        for(auto &guard : guards){
            int r = guard[0], c = guard[1];
            mat[r][c] = 1;
        }
        // Guarding cells //
        for(auto &guard : guards){
            int r = guard[0], c = guard[1];
            // 4 Cardinal Directions //
            for(int k=0; k<4; k++){
                int nextR = r + dirRow[k];
                int nextC = c + dirCol[k];
                // Moving into the single direction //
                while( isCellValid(m, n, nextR, nextC) && (mat[nextR][nextC] == 0 || mat[nextR][nextC] == -1) ){
                    mat[nextR][nextC] = -1;
                    nextR = nextR + dirRow[k];
                    nextC = nextC + dirCol[k];
                }
            }
        }
        // Finding the number of unguarded cells //
        int unguardedCells = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if( mat[i][j] == 0 ){
                    unguardedCells += 1;
                }
            }
        }
        return unguardedCells;
    }
};