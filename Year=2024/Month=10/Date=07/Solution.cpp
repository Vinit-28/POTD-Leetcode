// Problem Link : https://leetcode.com/problems/minimum-string-length-after-removing-substrings/


// Solution //
class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        int n = s.length();
        for(int i=n-1; i>=0; i--){
            if( !st.empty() && ((st.top()=='B' && s[i]=='A') || (st.top()=='D' && s[i]=='C')) ){
                st.pop();
            } else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
};