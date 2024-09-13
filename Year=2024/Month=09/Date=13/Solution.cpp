// Problem Link : https://leetcode.com/problems/xor-queries-of-a-subarray/description/


// Solution //
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int prefix[n];
        int val = 0;
        vector<int> ans;
        for(int i=0; i<n; i++){
            val ^= arr[i];
            prefix[i] = val;
        }
        for(auto &q : queries){
            int l = q[0], r = q[1];
            int val = (l==0? prefix[r] : prefix[r] ^ prefix[l-1]);
            ans.push_back(val);
        }
        return ans;
    }
};