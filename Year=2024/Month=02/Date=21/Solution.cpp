// Problem Link : https://leetcode.com/problems/bitwise-and-of-numbers-range/description/


// Solution //
class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        int finalValue = 0;
        for(int bitIdx=0; bitIdx<=31; bitIdx++){
            // Trying to make the bitIdx bit to 0 in the final value //
            int finalBit;
            int leftBit = (left>>bitIdx)&1;
            int rightBit = (right>>bitIdx)&1;
            if( leftBit==1 && rightBit==1 ){
                // Finding the number having bitIdx bit equals 0 //
                int mask = (1<<bitIdx);
                int num = right - mask;
                if( num >= left && num <= right ){
                    finalBit = 0;
                } else{
                    finalBit = 1;
                }
            } else{
                finalBit = 0;
            }
            finalValue += (finalBit<<bitIdx);
        }
        return finalValue;
    }
}
