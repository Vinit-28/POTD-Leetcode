// Problem Link : https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/


// Solution //
class Solution {
public:
    bool checkPowersOfThree(int n) {
        if( n%3 == 2 ) return false;
        if( n <= 1 ) return true;
        int num = 1;
        while( (num*3) <= n ){
            num *= 3;
        }
        return (n-num) >= num? false : checkPowersOfThree(n-num);
    }
};