// Problem Link : https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/


// Solution //
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int min1=INT_MAX, min2=INT_MAX, max1=INT_MIN, max2=INT_MIN;
        for(auto &ele : nums){
            if( min1 > ele ){
                min2 = min1, min1 = ele;
            } else if( min2 > ele ){
                min2 = ele;
            } 
            if( max1 < ele ){
                max2 = max1, max1 = ele;
            } else if( max2 < ele ){
                max2 = ele;
            }
        }
        return (max1*max2) - (min1*min2);
    }
};
