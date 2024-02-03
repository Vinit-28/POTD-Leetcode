// Problem Link : https://leetcode.com/problems/partition-array-for-maximum-sum/description/


// Solution //
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        int dp[n+1];
        dp[n] = 0;
        dp[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i] = 0;
            int maxEle = arr[i];
            int limit = min(i+k, n);
            for(int j=i;j<limit;j++){
                maxEle = max(maxEle, arr[j]);
                int len = j-i+1;
                dp[i] = max(dp[i], (maxEle * len)+dp[j+1]);
            }
        }
        return dp[0];
    }
};