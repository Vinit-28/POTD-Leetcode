// Problem Link : https://leetcode.com/problems/remove-k-digits/description/


// Solution //
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int removed = 0;
        string res = "";
        // Trying to make the string in increasing order //
        for(auto d: num){
            while( !st.empty() && removed < k && d < st.top() ){
                st.pop();
                removed += 1;
            }
            st.push(d);
        }
        if( removed < k ){
            // Removing the big digits //
            while( removed < k ){
                st.pop();
                removed += 1;
            }
        }
        // Stroing the result in reverse direction (as it is a stack) //
        while( st.empty()==false ){
            res += st.top();
            st.pop();
        }
        // Reversing the number //
        reverse(res.begin(), res.end());
        res = removeTrailingZeros(res);
        return res.empty()? "0" : res;
    }

private:
    string removeTrailingZeros(string num){
        int idx = 0;
        while( idx<num.size() && num[idx]=='0' ){
            idx += 1;
        }
        return num.substr(idx);
    }
};