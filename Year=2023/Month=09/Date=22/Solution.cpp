// Problem Link : https://leetcode.com/problems/is-subsequence/description/


// Solution //
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        int sLen = s.size(), tLen = t.size();
        while( i<sLen && j<tLen ){
            if( s[i] == t[j] ){
                i += 1;
            }
            j += 1;
        }
        return i==sLen;
    }
};