// Problem Link : https://leetcode.com/problems/number-complement/description/



// Solution //
class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        bool haveFoundSetBit = false;
        for(int i=30; i>=0; i--){
            int bit = (num>>i)&1;
            if( bit == 0 && haveFoundSetBit ){
                res += (1<<i);
            } else if( bit == 1 ){
                haveFoundSetBit = true;
            }
        }
        return res;
    }
};