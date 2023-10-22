// Problem Link : https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/


// Solution //
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        stack<int> st;
        int n = nums.size();
        int preMax[n], ans = INT_MIN;
        for(int i=0;i<n;i++){
            while( st.empty()==false && nums[st.top()] >= nums[i] ){
                int idx = st.top(); st.pop();
                int left = preMax[idx], right = i-1;
                if( left <= k && k <= right ){
                    ans = max(ans, (right-left+1)*nums[idx]);
                }
            }
            if( st.empty() ){
                preMax[i] = 0;
            } else{
                preMax[i] = st.top()+1;
            }
            st.push(i);
        }
        while( st.empty()==false ){
            int idx = st.top(); st.pop();
            int left = preMax[idx], right = n-1;
            if( left <= k && k <= right ){
                ans = max(ans, (right-left+1)*nums[idx]);
            }
        }
        return ans;
    }
};