// Problem Link : https://leetcode.com/problems/decode-ways/description/


// Solution //
class Solution {
public:
    int getNum(char &a, char &b){
        return (a-'0') * 10 + (b-'0');
    }

    int numDecodings(string s) {
        // Declaration //
        int n = s.length();
        int dp[n+1];
        // Initialization //
        dp[n] = 1;
        dp[n-1] = s[n-1] == '0'? 0 : 1;
        // Core Logic //
        for(int i=n-2;i>=0;i--){
            if( s[i] == '0' ){
                dp[i] = 0;
            } else {
                dp[i] = dp[i+1];
                dp[i] += (getNum(s[i], s[i+1]) <= 26)? dp[i+2] : 0;
            }
        }
        return dp[0];
    }
};