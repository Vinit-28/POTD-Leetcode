// Problem Link : https://leetcode.com/problems/maximum-score-from-removing-substrings/description/


// Solution //
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int ans = 0;
        if( x>y ){
            auto p1 = helper(s, "ab", x);
            auto p2 = helper(p1.first, "ba", y);
            ans = p1.second + p2.second;
        } else {
            auto p1 = helper(s, "ba", y);
            auto p2 = helper(p1.first, "ab", x);
            ans = p1.second + p2.second;
        }
        return ans;
    }

    pair<string,int> helper(string s, string rem, int val){
        stack<char> st;
        int points = 0;
        for(auto &ch : s){
            st.push(ch);
            while( st.size()>1 ){
                auto c2 = st.top(); st.pop();
                auto c1 = st.top(); st.pop();
                if( c1 != rem[0] || c2 != rem[1] ){
                    st.push(c1);
                    st.push(c2);
                    break;
                }
                points += val;
            }
        }
        string str = "";
        while( !st.empty() ){
            str += st.top(); st.pop();
        }
        reverse(begin(str), end(str));
        return {str, points};
    }
};