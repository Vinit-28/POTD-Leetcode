// Problem Link : https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/


// Solution //
using ll = long long;
class Solution {
public:
    long long findScore(vector<int>& nums) {
        stack<int> st;
        ll ans = 0;
        for(auto &ele : nums){
            if( st.empty() || st.top() > ele ){
                st.push(ele);
            } else{
                bool take = true;
                while( st.empty()==false ){
                    if( take ) ans += st.top();
                    st.pop();
                    take = !take;
                }
            }
        }
        bool take = true;
        while( st.empty()==false ){
            if( take ) ans += st.top();
            st.pop();
            take = !take;
        }
        return ans;
    }
};