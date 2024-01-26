// Problem Link : https://leetcode.com/problems/out-of-boundary-paths/description/


// Solution //
class Solution {
public:
    int m,n;
    int dirRow[4] = {1,-1,0,0};
    int dirCol[4] = {0,0,1,-1};
    long MOD = 1e9+7;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        map<pair<int, int>, int> dp[maxMove+1];
        this->m = m, this->n = n;
        int totalPaths = 0;

        for(int movesLeft=maxMove;movesLeft>0;movesLeft--){
            totalPaths = add(totalPaths, helper(startRow, startColumn, movesLeft, dp));
        }
        return totalPaths;
    }

    int helper(int row, int col, int movesLeft, map<pair<int, int>, int> dp[]){
        if( movesLeft == 1 ){
            return getOneMovePaths(row, col);
        } else if( movesLeft > 1 ) {
            if( dp[movesLeft].find({row, col}) == dp[movesLeft].end() ){
                int paths = 0;
                for(int idx=0;idx<4;idx++){
                    int nxtRow = row + dirRow[idx];
                    int nxtCol = col + dirCol[idx];
                    if( isValid(nxtRow, nxtCol) ){
                        paths = add(paths, helper(nxtRow, nxtCol, movesLeft-1, dp));
                    }
                }
                dp[movesLeft][{row, col}] = paths;
            }
            return dp[movesLeft][{row, col}];
        }
        return 0;
    }

    bool isValid(int row, int col){
        return !(row<0 || col<0 || row>=m || col>=n);
    }

    int getOneMovePaths(int row, int col){
        int paths = 0;
        if( row==0 ) paths += 1;
        if( col==0 ) paths += 1;
        if( row==m-1 ) paths += 1;
        if( col==n-1 ) paths += 1;
        return paths;
    }

    int add(int value1, int value2){
        return ((value1%MOD) + (value2%MOD))%MOD;
    }
};