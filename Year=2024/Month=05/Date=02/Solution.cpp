// Problem Link : https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/


// Solution //
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st;
        int ans = -1;
        for(auto &ele : nums){
            if( st.find(-ele) != st.end() ){
                ans = max(ans, abs(ele));
            }
            st.insert(ele);
        }
        return ans;
    }
};
