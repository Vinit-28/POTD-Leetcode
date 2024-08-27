// Problem Link : https://leetcode.com/problems/strange-printer/description/



// Solution //
class Solution {
public:
    int dp[101][101];
    int strangePrinter(string s) {
        memset(dp, -1, sizeof(dp));
        return helper(s, 0, s.length()-1);
    }
    
    int helper(string &s, int l, int r){
        if( l > r ){
            return 0;
        } else if( l == r ){
            return 1;
        } else if( dp[l][r] == -1 ){
            int ans = INT_MAX;
            for(int i=l; i<r; i++){
                int left = helper(s, l, i);
                int right = helper(s, i+1, r);
                ans = min(ans, left+right);
            }
            dp[l][r] = (s[l]==s[r]? ans-1 : ans); // Edge Case --> "aba" //
        }
        return dp[l][r];
    }
};