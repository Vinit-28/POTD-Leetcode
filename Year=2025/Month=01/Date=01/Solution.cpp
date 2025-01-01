// Problem Link : https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/


// Solution //
class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0;
        int n = s.length();
        int maxAns = 0;
        for(auto &ch : s) totalOnes += ch=='1';
        int zeros = 0, ones = 0;
        for(int i=0; i<n-1; i++){
            zeros += s[i]=='0';
            ones += s[i]=='1';
            int remOnes = totalOnes - ones;
            maxAns = max(maxAns, remOnes+zeros);
        }
        return maxAns;
    }
};