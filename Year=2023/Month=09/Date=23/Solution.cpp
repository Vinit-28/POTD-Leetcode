// Problem Link : https://leetcode.com/problems/longest-string-chain/description/


// Solution //
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size(), dp[n], ans = 1; 
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<n;i++){
            ans = max(ans, helper(words, n, i, dp));
        }
        return ans;
    }

    int helper(vector<string>& words, int &n, int idx, int dp[]){
        if( dp[idx] == -1 ){
            string word = words[idx];
            dp[idx] = 1;
            for(int i=0;i<n;i++){
                if( isPredecessor(word, words[i]) ){
                    dp[idx] = max(dp[idx], helper(words, n, i, dp)+1);
                }
            }
        }
        return dp[idx];
    }

    bool isPredecessor(string &prev, string &next){
        int prevLen = prev.length(), nextLen = next.length();
        if( (nextLen - prevLen) != 1 ) return false;
        int prevIdx = 0, nextIdx = 0;
        bool isMisMatch = false;
        while( prevIdx < prevLen && nextIdx < nextLen ){
            if( prev[prevIdx] != next[nextIdx] ){
                if( isMisMatch ) return false;
                isMisMatch = true;
                nextIdx += 1;
            } else{
                prevIdx += 1;
                nextIdx += 1;
            }
        }
        return true;
    }
};