// Problem Link : https://leetcode.com/problems/sort-array-by-increasing-frequency/description/


// Solution //
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto &ele :nums){
            mpp[ele] += 1;
        }
        vector<pair<int,int>> arr(begin(mpp), end(mpp));
        sort(begin(arr), end(arr), [](pair<int,int> &a, pair<int,int> &b){
            return a.second < b.second || (a.second == b.second && a.first > b.first);
        });
        vector<int> ans;
        for(auto &p : arr){
            int ele = p.first, freq = p.second;
            for(int idx=0; idx<freq; idx++) ans.push_back(ele);
        }
        return ans;
    }
};