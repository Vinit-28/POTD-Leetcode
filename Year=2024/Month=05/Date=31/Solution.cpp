// Problem Link : https://leetcode.com/problems/single-number-iii/description/


// Solution //
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long val = 0;
        // Xor of (a, b) //
        for(auto &ele : nums) val ^= ele;
        // Finding the bit(rightmost) index where a & b differes //
        int diffBitIdx = getDiffBitIndex(abs(val));
        int b1 = 0, b2 = 0;
        // Segregating every element on the bit indexed bit basis,
        // either the number will have 0 or 1 on that bit index,
        // b1 represents xor of all numbers having bit on diffBitIndex = 0
        // b2 represents xor of all numbers having bit on diffBitIndex = 1
        for(auto &ele : nums){
            int bit = (ele >> diffBitIdx)&1;
            if( bit == 0 ) b1 ^= ele;
            else b2 ^= ele;
        }
        return {b1, b2};
    }

    int getDiffBitIndex(long val){
        for(int idx=0; idx<32; idx++){
            int bit = (val>>idx)&1;
            if( bit == 1 ){
                return idx;
            }
        }
        return -1;
    }
};