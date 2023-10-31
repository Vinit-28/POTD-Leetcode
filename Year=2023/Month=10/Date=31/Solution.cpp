// Problem Link : https://leetcode.com/problems/find-the-original-array-of-prefix-xor/description/


// Solution //
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(n);
        ans[0] = pref[0];
        for(int i=1;i<n;i++){
            ans[i] = (pref[i-1] xor pref[i]);
        }   
        return ans;
    }
};