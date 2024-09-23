// Problem Link : https://leetcode.com/problems/extra-characters-in-a-string/description/


// Solution //
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        vector<int> dp(n+1, INT_MAX);
        set<string> st(begin(dictionary), end(dictionary));
        dp[n] = 0;
        for(int from=n-1; from>=0; from--){
            string sub = "";
            for(int to=from; to<n; to++){
                sub += s[to];
                int extra = dp[to+1] + (st.count(sub)==0? sub.length() : 0);
                dp[from] = min(dp[from], extra);
            }
        }
        return dp[0];
    }
};