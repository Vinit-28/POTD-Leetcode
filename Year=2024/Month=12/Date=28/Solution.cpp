// Problem Link : https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/


// Solution //
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int targetSubarrays = 3;
        vector<int> ps(n);
        vector<vector<int>> dp(n+1, vector<int>(targetSubarrays+1, 0));
        // Prefix Sum //
        ps[0] = nums[0];
        for(int i=1; i<n; i++){
            ps[i] = ps[i-1] + nums[i];
        } 
        // Filling up the DP table //
        // Base Case //
        for(int rem=1; rem<=targetSubarrays; rem++){
            dp[n][rem] = -1e9;
        }
        // DP Table //
        for(int idx=n-1; idx>=0; idx--){
            for(int rem=targetSubarrays; rem>0; rem--){
                int res = -1e9;
                // Start subarray from here //
                if( (n-idx) >= k ){
                    int windowSum = idx==0? ps[idx+k-1] : ps[idx+k-1]-ps[idx-1];
                    res = dp[idx+k][rem-1] + windowSum;
                }
                // Do not start from here //
                res = max(res, dp[idx+1][rem]);
                dp[idx][rem] = res;
            }
        }
        // Finding the indices( or path) //
        vector<int> indices;
        int idx = 0;
        int rem = targetSubarrays;
        while( idx < n && rem > 0 ){
            int start = -1e9;
            int dontStart = -1e9;
            // Start subarray from here //
            if( (n-idx) >= k ){
                int windowSum = idx==0? ps[idx+k-1] : ps[idx+k-1]-ps[idx-1];
                start = dp[idx+k][rem-1] + windowSum;
            }
            // Do not start from here //
            dontStart = dp[idx+1][rem];
            // Finding the path //
            if( start >= dontStart ){
                indices.push_back(idx);
                idx += k;
                rem -= 1;
            } else{
                idx += 1;
            }
        }
        return indices;
    }
};