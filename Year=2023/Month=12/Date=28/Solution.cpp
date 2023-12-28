// Problem Link : https://leetcode.com/problems/string-compression-ii/description/


// Solution //
int dp[101][27][101][101];
class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return s.length()==k? 0 : helper(s, 0, 26, 0, k);
    }

    int helper(string &s, int idx, int lastChar, int lastCharFreq, int k){
        if( idx >= s.length() ){
            return getLen(lastCharFreq);
        } else if( dp[idx][lastChar][lastCharFreq][k] == -1 ){
            // include //
            int inc = INT_MAX;
            if( lastChar == (s[idx]-'a') ){
                inc = helper(s, idx+1, lastChar, lastCharFreq+1, k);
            } else{
                inc = getLen(lastCharFreq) + helper(s, idx+1, s[idx]-'a', 1, k);
            }
            // Exclude //
            int exc = k>0? helper(s, idx+1, lastChar, lastCharFreq, k-1) : INT_MAX;
            dp[idx][lastChar][lastCharFreq][k] = min(inc, exc);
        }
        return dp[idx][lastChar][lastCharFreq][k];
    }

    int getLen(int &count){
        if( count == 0 ) return 0;
        else if( count == 1 ) return 1;
        return count<10? 2 : count<100? 3 : 4;
    }
};