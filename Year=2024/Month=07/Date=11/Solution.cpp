// Problem Link : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/


// Solution //
class Solution {
public:
    string reverseParentheses(string s) {
        string temp = "";
        stack<string> st;
        for(auto &ch : s){
            if( ch == '(' ){
                st.push(temp);
                temp = "";
            } else if( ch == ')' ){
                reverse(begin(temp), end(temp));
                string prev = st.top(); st.pop();
                temp = prev + temp;
            } else{
                temp += ch;
            }
        }
        return temp;
    }
};