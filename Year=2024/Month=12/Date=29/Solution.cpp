// Problem Link : https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/


// Solution //
class Solution {
private:
    int MOD = (int)1e9+7;
public:
    int numWays(vector<string>& words, string target) {
        int wordLen = words[0].length();
        int targetLen = target.length();
        if( targetLen > wordLen ) return 0;
        
        vector<vector<int>> wordsHavingChar(wordLen, vector<int>(26, 0));
        vector<vector<int>> dp = vector<vector<int>>(targetLen+1, vector<int>(wordLen+1, 0));

        for(int idx=0; idx<wordLen; idx++){
            for(auto &word : words){
                wordsHavingChar[idx][word[idx]-'a'] += 1;
            }
        }
        for(int idx=0; idx<=wordLen; idx++){
            dp[targetLen][idx] = 1;
        }
        for(int targetIdx=targetLen-1; targetIdx>=0; targetIdx--){
            for(int wordIdx=wordLen-1; wordIdx>=0; wordIdx--){
                int consider = 0, notConsider = 0;
                char targetChar = target[targetIdx];
                // Consider current word idx //
                if( wordsHavingChar[wordIdx][targetChar-'a'] > 0 ){
                    int wordsCount = wordsHavingChar[wordIdx][targetChar-'a'];
                    consider = (wordsCount * (long)dp[targetIdx+1][wordIdx+1])%MOD;
                }
                // Do not consider current word idx //
                notConsider = dp[targetIdx][wordIdx+1];
                int res = (consider + notConsider)%MOD;
                dp[targetIdx][wordIdx] = res;
            }
        }
        return dp[0][0];
    }
};