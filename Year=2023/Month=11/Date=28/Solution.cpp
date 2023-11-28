// Problem Link : https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/description/


// Solution //
class Solution {
public:
    long MOD = 1e9+7;
    int numberOfWays(string corridor) {
        int n = corridor.size(), dp[n][3];
        memset(dp, -1, sizeof(dp));
        return helper(corridor, 0, 0, dp);
    }

    int helper(string &corridor, int idx, int seats, int dp[][3]){
        if( idx >= corridor.size() ){
            return seats == 2;
        } else if( seats > 2 ){
            return 0;
        } else if( dp[idx][seats] == -1 ){
            if( seats <= 1 ){
                int newSeats = seats + (corridor[idx]=='S'? 1 : 0);
                dp[idx][seats] = helper(corridor, idx+1, newSeats, dp);
            } else{
                int newSeats = corridor[idx]=='S'? 1 : 0;
                // Adding the divider //
                dp[idx][seats] = helper(corridor, idx+1, newSeats, dp);
                // Continuing with existing seats/pattern //
                dp[idx][seats] = add(dp[idx][seats], helper(corridor, idx+1, newSeats+seats, dp));
            }
        }
        return dp[idx][seats];
    }

    int add(int a, int b){
        return ((a%MOD) + (b%MOD))%MOD;
    }
};