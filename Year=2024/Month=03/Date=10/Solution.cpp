// Problem Link : https://leetcode.com/problems/intersection-of-two-arrays/description/


// Solution //
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool hmap[1001];
        vector<int> ans;
        memset(hmap, false, sizeof(hmap));
        for(auto &ele : nums1){
            hmap[ele] = true;
        }
        for(auto &ele : nums2){
            if( hmap[ele] ){
                ans.push_back(ele);
                hmap[ele] = false;
            }
        }
        return ans;
    }
};