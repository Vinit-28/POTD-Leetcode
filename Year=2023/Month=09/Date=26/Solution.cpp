// Problem Link : https://leetcode.com/problems/remove-duplicate-letters/description/


// Solution //
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int lastOccur[26], n = s.length();
        bool hmap[26];
        stack<char> st;
        string ans = "";
        memset(lastOccur, -1, sizeof(lastOccur));
        memset(hmap, false, sizeof(hmap));
        for(int i=0;i<n;i++){
            lastOccur[s[i]-'a'] = i;
        }
        for(int i=0;i<n;i++){
            if( !hmap[s[i]-'a'] ){
                while( !st.empty() && st.top() > s[i] && lastOccur[st.top()-'a'] > i ){
                    hmap[st.top()-'a'] = false;
                    st.pop();
                }
                st.push(s[i]);
                hmap[s[i]-'a'] = true;
            }
        }
        while( !st.empty() ){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};