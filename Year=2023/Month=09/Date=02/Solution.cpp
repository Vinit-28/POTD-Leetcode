// Problem Link : https://leetcode.com/problems/extra-characters-in-a-string/


// Solution -- Recursion + Memoization(DP) //
class Solution {
public:
    int dp[51];

    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp, -1, sizeof(dp));
        map<string, bool> dict;
        for(auto &word : dictionary){
            dict[word] = true;
        }
        return helper(dict, s, 0, "");
    }

    int helper(map<string, bool> &dict, string &s, int idx, string word){
        if( idx >= s.size() ){
            return (dict.find(word)==dict.end())? word.size() : 0;
        } else{
            // Include //
            int include = helper(dict, s, idx+1, word + s[idx]);
            int extraChars = (dict.find(word)==dict.end())? word.size() : 0;
            if( dp[idx] == -1 ){
                // Exclude //
                word = "";
                dp[idx] = helper(dict, s, idx+1, word + s[idx]);
            }
            return min(include, dp[idx]+extraChars);
        }
        return 0;
    }
};



// Solution -- Iterative DP //
class Solution {
public:

    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size(), dp[n+1];
        map<string, bool> dict;
        // Inititalization //
        dp[0] = 0;
        for(auto &word : dictionary){
            dict[word] = true;
        }
        // Main Logic //
        for(int i=1;i<=n;i++){
            dp[i] = INT_MAX;
            for(int j=0;j<i;j++){
                string substr = s.substr(j, (i-j));
                if( dict.find(substr) != dict.end() ){
                    dp[i] = min(dp[i], dp[j]);
                } else{
                    dp[i] = min(dp[i], dp[j]+(i-j));
                }
            }
        }
        return dp[n];
    }
};