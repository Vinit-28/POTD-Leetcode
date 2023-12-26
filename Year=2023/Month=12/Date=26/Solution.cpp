// Problem Link : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/


// Solution //
class Solution {
public:
    int dp[31][1001];
    long MOD = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return helper(k, n, target, 0, 0);
    }

    int helper(int &k, int &n, int &target, int idx, int sum){
        if( idx == n ){
            return sum == target;
        } else if( sum >= target ){
            return 0;
        } else if( dp[idx][sum] == -1 ){
            int ways = 0;
            for(int i=1;i<=k;i++){
                ways = ((helper(k, n, target, idx+1, sum+i)%MOD) + (ways%MOD))%MOD;
            }
            dp[idx][sum] = ways;
        }
        return dp[idx][sum];
    }
};