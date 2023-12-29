// Problem Link : https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/


// Solution //
class Solution {
public:
    int dp[300][11];
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(dp, -1, sizeof(dp));
        int n = jobDifficulty.size();
        return n<d? -1 : helper(jobDifficulty, n, 1, d, jobDifficulty[0]);
    }

    int helper(vector<int> &jobDifficulty, int &n, int idx, int d, int currMax){
        if( idx == n ){
            return currMax;
        } else{
            // Continue with the coming subarray //
            int a = ((n-idx) < d)? INT_MAX : helper(jobDifficulty, n, idx+1, d, max(currMax, jobDifficulty[idx]));
            // Start new subarray with current element //
            int b;
            if( dp[idx][d] == -1 ){
                dp[idx][d] = d<=1? INT_MAX : + helper(jobDifficulty, n, idx+1, d-1, jobDifficulty[idx]);
            }
            b = dp[idx][d]==INT_MAX? dp[idx][d] : dp[idx][d]+currMax;
            return min(a, b);
        }
        return -1;
    }
};