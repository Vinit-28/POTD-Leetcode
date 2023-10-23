// Problem Link : https://leetcode.com/problems/power-of-four/description/


// Solution //
class Solution {
public:
    bool isPowerOfFour(int n) {
        if( n == 1 ) return true;
        if( n <= 0 ) return false;
        int unsetBits = 0, setBits = 0;
        for(int i=0;i<32;i++){
            int bit = (n>>i)&1;
            if( bit == 0 && setBits == 0 ){
                unsetBits += 1;
            } else if( bit == 1 ){
                setBits += 1;
            }
        }
        if( !(unsetBits&1) && unsetBits>0 && setBits==1 ){
            return true;
        }
        return false;
    }
};