// Problem Link : https://leetcode.com/problems/minimum-array-end/description/


// Solution //
using ll = long long;
class Solution {
public:
    ll minEnd(int n, int x) {
        if( n == 1 ) return ll(x);
        ll lastNum = x;
        ll num = n-1;
        int bitIdx = 0;
        for(int i=0; i<=60; i++){
            int lastNumBit = (lastNum>>i)&1;
            if( lastNumBit == 0 ){
                ll numBit = (num>>bitIdx)&1;
                lastNum += (numBit<<i);
                bitIdx += 1;
            }
        }
        return lastNum;
    }
};