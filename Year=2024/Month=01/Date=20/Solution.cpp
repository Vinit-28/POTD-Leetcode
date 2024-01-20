// Problem Link : https://leetcode.com/problems/sum-of-subarray-minimums/description/


// Solution //
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int leftBoundaries[n];
        int ans = 0;
        long MOD = 1e9+7;
        stack<int> st;
        for(int i=0;i<n;i++){
            while( st.empty()==false && arr[st.top()] >= arr[i] ){
                int idx = st.top(); st.pop();
                int leftb = leftBoundaries[idx], rightb = i-1;
                int subCount = getSubarrayCount(leftb, idx, rightb);
                ans = (ans + ((subCount%MOD)*(arr[idx]%MOD)))%MOD;
            }
            leftBoundaries[i] = st.empty()? 0 : st.top()+1;
            st.push(i);
        }
        while( st.empty()==false ){
            int idx = st.top(); st.pop();
            int leftb = leftBoundaries[idx], rightb = n-1;
            int subCount = getSubarrayCount(leftb, idx, rightb);
            ans = (ans + ((subCount%MOD)*(arr[idx]%MOD)))%MOD;
        }
        return ans;
    }

    int getSubarrayCount(int leftb, int idx, int rightb){
        int rightCount = (rightb - idx)+1;
        return rightCount + (rightCount * (idx - leftb));
    }
};