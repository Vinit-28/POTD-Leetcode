// Problem Link : https://leetcode.com/problems/student-attendance-record-ii/description/


// Solution //
class Solution {
public:
    int MOD = 1e9+7;
    int checkRecord(int n) {
        int dp[n+1][3][2];
        memset(dp, -1, sizeof(dp));
        return helper(n, 0, 0, dp);
    }

    int helper(int days, int late, int absentStatus, int dp[][3][2]){
        if( days == 0 ){
            return 1;
        } else if( dp[days][late][absentStatus] == -1 ){
            int ways = 0;
            // Not Absent on any previous days //
            if( absentStatus == 0 ){
                ways = (ways + helper(days-1, 0, 1, dp))%MOD; // A //
            }
            // No more than 2 L together //
            if( late < 2 ){
                ways = (ways + helper(days-1, late+1, absentStatus, dp))%MOD; // L //
            }
            // P can be appended with everyone //                
            ways = (ways + helper(days-1, 0, absentStatus, dp))%MOD;
            dp[days][late][absentStatus] = ways;
        }
        return dp[days][late][absentStatus];
    }
};