// Problem Link : https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/


// Solution //
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> arr;
        vector<int> ans;
        int idx = 0;
        for(auto &row : mat){
            int soldiers = lower_bound(row.begin(), row.end(), 0, greater<int>()) - row.begin();
            arr.push_back({soldiers, idx++});
        }
        sort(arr.begin(), arr.end());
        for(int i=0;i<k;i++){
            ans.push_back(arr[i][1]);
        }
        return ans;
    }
};