// Problem Link : https://leetcode.com/problems/median-of-two-sorted-arrays/description/


// Solution //
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int totalEles = n1+n2;
        int medianIdx = totalEles/2, medianIdxEle;
        int p1, p2;
        setProportions(nums1, nums2, medianIdx, p1, p2);
        if( p1 < n1 && (p2 >= n2 || nums1[p1] <= nums2[p2]) ){
            medianIdxEle = double(nums1[p1]);
        } else{
            medianIdxEle = double(nums2[p2]);
        }
        if( totalEles & 1 ){ // Odd //
            return double(medianIdxEle);
        } else{ // Even //
            int medianIdxPrevEle;
            // Finding the medianIdxPrevEle //
            if( p1 == 0 ){
                medianIdxPrevEle = double(nums2[p2-1]);
            } else if( p2 == 0 ){
                medianIdxPrevEle = double(nums1[p1-1]);
            } else{
                medianIdxPrevEle = max(nums1[p1-1], nums2[p2-1]);
            }
            return double(medianIdxEle + medianIdxPrevEle)/2.0;
        }
        return 0;
    }

    void setProportions(vector<int>& nums1, vector<int>& nums2, int totalEles, int &p1, int &p2){
        int l = 0, u = totalEles, m = (l+u)/2;
        while( l<=u ){
            p1 = m, p2 = totalEles - m;
            if( p1 > nums1.size() ){
                u = m-1;
            } else if( p2 > nums2.size() ){
                l = m+1;
            } else if( p2 < nums2.size() && p1 > 0 && nums1[p1-1] > nums2[p2] ){
                u = m-1;
            } else if( p1 < nums1.size() && p2 > 0 && nums2[p2-1] > nums1[p1] ){
                l = m+1;
            } else{
                return;
            }
            m = (l+u)/2;
        }
    }
};