// Problem Link : https://leetcode.com/problems/minimize-xor/description/


// Solution //
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBits = __builtin_popcount(num2);
        int x = 0;
        for(int bitIdx=30; (bitIdx>=0 && setBits>0); bitIdx--){
            int num1Bit = (num1>>bitIdx)&1;
            if( num1Bit == 1 ){
                x += (1<<bitIdx);
                setBits -= 1;
            }
        }
        for(int bitIdx=0; (bitIdx<31 && setBits>0); bitIdx++){
            int num1Bit = (num1>>bitIdx)&1;
            if( num1Bit == 0 ){
                x += (1<<bitIdx);
                setBits -= 1;
            }
        }
        return x;
    }
};