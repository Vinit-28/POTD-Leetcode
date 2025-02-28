// Problem Link : https://leetcode.com/problems/shortest-common-supersequence/description/


// Solution //
class Solution {
private:
    vector<vector<int>> dp;
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        dp = vector<vector<int>>(m+1, vector<int>(n+1, -1));
        helper(s1, s2, 0, 0);
        string ans = "";
        int i = 0, j = 0;
        while( i<m || j<n ){
            if( i<m && j<n && s1[i] == s2[j] ){
                ans += s1[i];
                i += 1, j += 1;
            } else{
                if( j>=n || (i<m && dp[i+1][j] < dp[i][j+1]) ){
                    ans += s1[i];
                    i += 1;
                } else{
                    ans += s2[j];
                    j += 1;
                }
            }
        }
        return ans;
    }
private:
    int helper(string &s1, string &s2, int i, int j){
        if( dp[i][j] == -1 ){
            int ans = 1e9;
            if( i < s1.length() && j < s2.length() ){
                if( s1[i] == s2[j] ) ans = helper(s1, s2, i+1, j+1)+1;
                else ans = min(helper(s1, s2, i+1, j), helper(s1, s2, i, j+1))+1;
            } else if( i < s1.length() ){
                ans = s1.length()-i;
            } else if( j < s2.length() ){
                ans = s2.length()-j;
            } else{
                ans = 0;
            }
            dp[i][j] = ans;
        }
        return dp[i][j];
    }
};