// Problem Link : https://leetcode.com/problems/painting-the-walls/description/


// Solution //
class Solution {
public:
    int dp[501][501];
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        return solver(cost, time, 0, n, n);
    }

    int solver(vector<int> &cost, vector<int> &time, int idx, int &n, int wallsLeft){
        if( wallsLeft <= 0 ){
            return 0;
        } else if( idx >= n ){
            return INT_MAX;
        } else if( dp[idx][wallsLeft] == -1 ){
            // exclude //
            int exclude = solver(cost, time, idx+1, n, wallsLeft);
            // include //
            int include = solver(cost, time, idx+1, n, wallsLeft-time[idx]-1);
            include += (include == INT_MAX)? 0 : cost[idx];
            dp[idx][wallsLeft] = min(include, exclude);
        }
        return dp[idx][wallsLeft];
    }
};