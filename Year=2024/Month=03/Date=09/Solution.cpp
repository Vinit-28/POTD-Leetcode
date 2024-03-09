// Problem Link : https://leetcode.com/problems/minimum-common-value/description/


// Solution //
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int idx1=0, idx2=0;
        while( idx1<n1 && idx2<n2 ){
            if( nums1[idx1] < nums2[idx2] ){
                idx1 += 1;
            } else if( nums1[idx1] > nums2[idx2] ){
                idx2 += 1;
            } else{
                return nums1[idx1];
            }
        }
        return -1;
    }
};