// Problem Link : https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/


// Solution //
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        int n = s1.length();
        char c1 = '!', c2 = '!';
        for(int idx=0; idx<n; idx++){
            if( s1[idx] != s2[idx] ){
                if( ++count > 2 || (s1[idx] != c2 && c2!='!') || (s2[idx] != c1 && c1!='!') ){
                    return false;
                }
                c1 = s1[idx];
                c2 = s2[idx];
            }
        }
        return count%2==0;
    }
};