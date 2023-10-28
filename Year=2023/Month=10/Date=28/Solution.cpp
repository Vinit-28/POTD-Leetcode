// Problem Link : https://leetcode.com/problems/count-vowels-permutation/description/


// Solution //
class Solution {
public:
    long MOD = 1e9+7;

    int countVowelPermutation(int n) {
        int ans = 0;
        long long a=1, e=1, i=1, o=1, u=1;
        for(int j=1;j<n;j++){
            long long aCurr = (e + i + u)%MOD;
            long long eCurr = (a + i)%MOD;
            long long iCurr = (e + o)%MOD;
            long long oCurr = i%MOD;
            long long uCurr = (i + o)%MOD;

            a=aCurr, e=eCurr, i=iCurr, o=oCurr, u=uCurr;
        }
        return (a+e+i+o+u)%MOD;
    }
};