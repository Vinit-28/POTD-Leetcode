// Problem Link : https://leetcode.com/problems/knight-dialer/description/


// Solution //
class Solution {
public:
    long MOD = 1e9+7;
    vector<int> moves[10] = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {0, 9, 3},
        {},
        {0, 1, 7},
        {2, 6},
        {1, 3},
        {4, 2}
    };

    int knightDialer(int n) {
        int dp[n+1][10];
        for(int i=1;i<=n;i++){
            if( i==1 ){
                for(int j=0;j<10;j++){
                    dp[i][j] = 1;
                }   
            } else{
                for(int j=0;j<10;j++){
                    dp[i][j] = 0;
                    for(auto &mv_idx: moves[j]){
                        dp[i][j] = ((dp[i][j]%MOD) + (dp[i-1][mv_idx]%MOD))%MOD;
                    }
                }
            }
        }
        int sum = 0;
        for(int i=0;i<10;i++){
            sum = ((sum%MOD) + (dp[n][i]%MOD))%MOD;
        }
        return sum;
    }
};
