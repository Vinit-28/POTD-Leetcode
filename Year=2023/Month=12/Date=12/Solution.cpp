// Problem Link : https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/


// Solution //
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m1 = 0, m2 = 0;
        for(auto &ele : nums){
            if( m1 < ele ){
                m2 = m1, m1 = ele;
            } else if( m2 < ele ){
                m2 = ele;
            }
        }
        return (m1-1) * (m2-1);
    }
};