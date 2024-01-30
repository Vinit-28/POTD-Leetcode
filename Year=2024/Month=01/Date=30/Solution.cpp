// Problem Link : https://leetcode.com/problems/evaluate-reverse-polish-notation/description/


// Solution //
class Solution {
public:
    bool isNumber(string str){
        return !(str=="+" || str=="-" || str=="*" || str=="/");
    }

    int getOperationResult(int a, int b, string opr){
        if( opr=="+" ) return a+b;
        if( opr=="-" ) return a-b;
        if( opr=="*" ) return a*b;
        return a/b;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto &token : tokens){
            if( isNumber(token) ){
                st.push(stoi(token));
            } else{
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(getOperationResult(a, b, token));
            }
        }
        return st.top();
    }
};
