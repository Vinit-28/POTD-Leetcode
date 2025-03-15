// Problem Link : https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/


// Solution //
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0, j = 0;
        while( i<n1 || j<n2 ){
            if( i<n1 && j<n2 ){
                if( nums1[i][0] == nums2[j][0] ){
                    ans.push_back({nums1[i][0], nums1[i++][1]+nums2[j++][1]});
                } else if( nums1[i][0] < nums2[j][0] ){
                    ans.push_back(nums1[i++]);
                } else{
                    ans.push_back(nums2[j++]);
                }
            } else if( i<n1 ){
                ans.push_back(nums1[i++]);
            } else{
                ans.push_back(nums2[j++]);
            }
        }
        return ans;
    }
};