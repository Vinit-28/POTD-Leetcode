// Problem Link : https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/


// Solution //
class Solution {
public:
    int MOD = 1e9+7;
    int dp[501][501];
    int numWays(int steps, int arrLen) {
        memset(dp, -1, sizeof(dp));
        return helper(steps, arrLen, 0);
    }

    int helper(int steps, int &arrLen, int idx){
        if( steps == 0 ){
            return idx==0;
        } else if( dp[steps][idx] == -1 ){
            int ways = 0;
            if( idx > 0 ){
                ways = add(ways, helper(steps-1, arrLen, idx-1));
            }
            if( idx < arrLen-1 ){
                ways = add(ways, helper(steps-1, arrLen, idx+1));
            }
            ways = add(ways, helper(steps-1, arrLen, idx));
            dp[steps][idx] = ways;
        }
        return dp[steps][idx];
    }

    int add(int a, int b){
        return ((a%MOD) + (b%MOD))%MOD;
    }
};