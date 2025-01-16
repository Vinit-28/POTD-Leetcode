// Problem Link : https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/


// Solution //
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int xor1 = (n2&1)? getArrayXor(nums1) : 0;
        int xor2 = (n1&1)? getArrayXor(nums2) : 0; 
        return xor1 xor xor2;
    }
private:
    int getArrayXor(vector<int> &arr){
        int val = 0;
        for(auto &ele : arr){
            val = val xor ele;
        }
        return val;
    }
};