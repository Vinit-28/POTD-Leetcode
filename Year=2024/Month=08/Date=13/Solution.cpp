// Problem Link : https://leetcode.com/problems/combination-sum-ii/description/



// Solution //
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        sort(begin(candidates), end(candidates));
        helper(candidates, 0, comb, ans, target);
        return ans;
    }

    void helper(vector<int> &can, int idx, vector<int> &comb, vector<vector<int>> &ans, int target){
        if( target < 0 ){
            return;
        } else if( idx == can.size() ){
            if( target == 0 ) ans.push_back(comb);
        } else{
            // Exclude only if the previous selected element is not you //
            if( comb.empty() || comb.back() != can[idx] ){
                helper(can, idx+1, comb, ans, target);
            }
            // Include //
            comb.push_back(can[idx]);
            helper(can, idx+1, comb, ans, target-can[idx]);
            comb.pop_back();
        }
    }
};