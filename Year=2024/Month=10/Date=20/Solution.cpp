// Problem Link : https://leetcode.com/problems/parsing-a-boolean-expression/description/


// Solution //
class Solution {
private:
    bool resolveOperation(vector<char> &booleans, char operation){
        bool res = booleans[0]=='t';
        if( operation == '!' ) return !res;
        for(auto &boolean : booleans){
            bool val = boolean=='t';
            res = (operation=='&'? res&&val : res||val);
        }
        return res;
    }
public:
    bool parseBoolExpr(string exp) {
        stack<char> st;
        for(auto &ch : exp){
            if( ch == ',' ) continue;
            if( ch != ')' ){
                st.push(ch);
            } else{
                vector<char> booleans;
                while( st.top() != '(' ){
                    booleans.push_back(st.top());
                    st.pop();
                }
                st.pop(); // To Remove '(' //
                char operation = st.top(); st.pop(); // Getting the Operation //
                bool res = resolveOperation(booleans, operation);
                st.push(res? 't':'f');
            }
        }
        return st.top()=='t';
    }
};