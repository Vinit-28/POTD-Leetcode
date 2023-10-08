// Problem Link : https://leetcode.com/problems/max-dot-product-of-two-subsequences/


// Solution //
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        return solve(nums1, nums2, 0, 0, dp);
    }

    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>> &dp){
        if( i >= nums1.size() || j >= nums2.size() ){
            return INT_MIN;
        } else if( i == nums1.size()-1 && j < nums2.size() ){
            return max(nums1[i] * nums2[j], solve(nums1, nums2, i, j+1, dp));
        } else if( j == nums2.size()-1 && i < nums1.size() ){
            return max(nums1[i] * nums2[j], solve(nums1, nums2, i+1, j, dp));
        } else if( dp[i][j] == INT_MAX ){
            int product = nums1[i] * nums2[j];
            int a = max(0, solve(nums1, nums2, i+1, j+1, dp)) + product;
            int b = solve(nums1, nums2, i+1, j, dp);
            int c = solve(nums1, nums2, i, j+1, dp);
            dp[i][j] = max({a,b,c});
        }
        return dp[i][j];
    }
};