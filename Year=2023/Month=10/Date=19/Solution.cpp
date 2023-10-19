// Problem Link : https://leetcode.com/problems/backspace-string-compare/description/


// Solution //
class Solution {
public:

    bool backspaceCompare(string s, string t) {
        int i = s.length()-1, j = t.length()-1;
        int b1 = 0, b2 = 0;
        while( i>=0 || j>=0 ){
            if( i>=0 && s[i] == '#' ){
                b1 += 1;
                i -= 1;
            } else if( j>=0 && t[j] == '#' ){
                b2 += 1;
                j -= 1;
            } else if( b1 > 0 ){
                i = max(-1, i-1);
                b1 -= 1;
            } else if( b2 > 0 ){
                j = max(-1, j-1);
                b2 -= 1;
            } else{
                if( (i < 0 || j < 0 || s[i] != t[j]) ){
                    return false;
                }
                i -= 1, j -= 1;
            }
        }
        return i==j;
    }
};