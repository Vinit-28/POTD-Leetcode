// Problem Link : https://leetcode.com/problems/subsets/description/


// Solution //
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        sort(nums.begin(), nums.end());
        vector<int> subset;
        helper(nums, 0, subset);
        return ans;
    }

    void helper(vector<int> &nums, int idx, vector<int> &subset){
        if( idx == nums.size() ){
            ans.push_back(subset);
        } else{
            // Exclude //
            helper(nums, idx+1, subset);
            // Include //
            subset.push_back(nums[idx]);
            helper(nums, idx+1, subset);
            subset.pop_back();
        }
    }
};