// Problem Link : https://leetcode.com/problems/2-keys-keyboard/description/



// Solution //
class Solution {
public:
    int minSteps(int n) {
        int dp[n+1];
        dp[0] = dp[1] = 0;
        for(int i=2; i<=n; i++){
            dp[i] = i;
            for(int j=2; j<=sqrt(i); j++){
                if( i%j == 0 ){
                    int d1 = j, d2 = i/j;
                    dp[i] = min(dp[i], dp[d1]+i/d1);
                    dp[i] = min(dp[i], dp[d2]+i/d2);
                }
            }
        }
        return dp[n];
    }
};