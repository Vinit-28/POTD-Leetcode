// Problem Link : https://leetcode.com/problems/count-ways-to-build-good-strings/description/


// Solution //
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, 0);
        int MOD = (int)1e9+7;
        for(int i=low; i<=high; i++) dp[i] = 1;
        for(int i=high; i>=0; i--){
            int res = dp[i];
            int z = i+zero;
            res = (res + (z<=high? dp[z] : 0))%MOD;
            int o = i+one;
            res = (res + (o<=high? dp[o] : 0))%MOD;
            dp[i] = res;
        }
        return dp[0];
    }
};