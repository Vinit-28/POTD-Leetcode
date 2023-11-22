// Problem Link : https://leetcode.com/problems/diagonal-traverse-ii/description/


// Solution //
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> diagonals;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int m = nums[i].size();
            for(int j=0;j<m;j++){
                int sum = i+j;
                diagonals[sum].push_back(nums[i][j]);
            }
        }
        for(auto &p : diagonals){
            auto &arr = p.second;
            for(int i=arr.size()-1;i>=0;i--){
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};
