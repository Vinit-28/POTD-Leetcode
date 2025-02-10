// Problem Link : https://leetcode.com/problems/clear-digits/description/


// Solution //
class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(auto &ch : s){
            if( ch>='a' && ch<='z' ){
                st.push(ch);
            } else{
                st.pop();
            }
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};