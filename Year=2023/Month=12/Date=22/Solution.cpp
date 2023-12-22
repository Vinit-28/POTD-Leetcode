// Problem Link : https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/


// Solution //
class Solution {
public:
    int maxScore(string s) {
        int n = s.length(), prefixSum[n];
        int ans = 0;
        prefixSum[0] = s[0] == '0'? 1 : 0;
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + (s[i] == '0'? 1 : 0);
        }
        for(int i=0;i<n-1;i++){
            int zeros = prefixSum[i];
            int ones = (n-i-1) - (prefixSum[n-1] - prefixSum[i]);
            ans = max(ans, (zeros + ones));
        }
        return ans;
    }
};