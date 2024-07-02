// Problem Link : https://leetcode.com/problems/intersection-of-two-arrays-ii/description/


// Solution //
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int hmap[1001] = {0};
        for(auto &ele : nums1) hmap[ele] += 1;
        for(auto &ele : nums2){
            if( --hmap[ele] >= 0 ){
                ans.push_back(ele);
            }
        }
        return ans;
    }
};