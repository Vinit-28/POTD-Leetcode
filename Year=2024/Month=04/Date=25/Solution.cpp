// Problem Link : https://leetcode.com/problems/longest-ideal-subsequence/description/


// Solution //
class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[26] = {0};
        int n = s.length();
        int ans = 0;
        for(int idx=n-1; idx>=0; idx--){
            int currCharIdx = int(s[idx]-'a');
            int maxChainSize = 0;
            int preLimit = max(0, currCharIdx-k);
            int postLimit = min(25, currCharIdx+k);
            char preLimitCh = char(preLimit + 'a');
            char postLimitCh = char(postLimit + 'a');

            // Moving Backward //
            for(char ch=s[idx]; ch>=preLimitCh; ch--){
                int charIdx = ch-'a';
                maxChainSize = max(maxChainSize, dp[charIdx]);
            }
            // Moving Forward //
            for(char ch=s[idx]; ch<=postLimitCh; ch++){
                int charIdx = ch-'a';
                maxChainSize = max(maxChainSize, dp[charIdx]);
            }
            dp[currCharIdx] = max(dp[currCharIdx], maxChainSize+1);
            ans = max(ans, dp[currCharIdx]);
        }
        return ans;
    }
};