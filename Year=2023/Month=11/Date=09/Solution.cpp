// Problem Link : https://leetcode.com/problems/count-number-of-homogenous-substrings/description/


// Solution //
class Solution {
public:
    long MOD = 1e9+7;

    int getSubstringsCount(long n){
        return (((n * (n+1))%MOD)/2)%MOD;
    }

    int countHomogenous(string s) {
        int len = s.length();
        int count = 1, lastMatchIdx = 0;
        int ans = 0;
        for(int i=1;i<len;i++){
            if( s[i] == s[lastMatchIdx] ){
                count += 1;
            } else{
                ans = (ans + getSubstringsCount(count))%MOD;
                count = 1;
                lastMatchIdx = i;
            }
        }
        ans = (ans + getSubstringsCount(count))%MOD;
        return ans;
    }
};