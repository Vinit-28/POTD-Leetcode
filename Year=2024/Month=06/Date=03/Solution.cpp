// Problem Link : https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/


// Solution //
class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        int n1 = s.length(), n2 = t.length();
        while( i<n1 && j<n2 ){
            if( s[i] == t[j] ){
                j += 1;
            }
            i += 1;
        }
        return (n2 - j);
    }
};