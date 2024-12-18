// Problem Link : https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/


// Solution //
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        vector<int> ans(n);
        for(int idx=n-1; idx>=0; idx--){
            while( st.empty()==false && prices[st.top()] > prices[idx] ){
                st.pop();
            }
            if( st.empty() ) ans[idx] = prices[idx];
            else ans[idx] = prices[idx] - prices[st.top()];
            st.push(idx);
        }
        return ans;
    }
};