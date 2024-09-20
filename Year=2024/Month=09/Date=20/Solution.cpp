// Problem Link : https://leetcode.com/problems/shortest-palindrome/description/


// Solution //
class Solution {
public:
    string shortestPalindrome(string s) {
        int insertions = charactersReq(s);
        string toInsert = s.substr(s.length()-insertions, insertions);
        reverse(begin(toInsert), end(toInsert));
        return toInsert + s;
    }

    int charactersReq(string s){
        string rev = s; reverse(begin(rev), end(rev));
        string text = s + "#" + rev;
        int n = text.size();
        vector<int> lps(n, 0);
        int i=1, j=0;
        while( i<n ){
            if( text[i] == text[j] ){
                lps[i++] = ++j;
            } else if( j==0 ){
                lps[i++] = 0;
            } else{
                j = lps[j-1];
            }
        }
        return s.length() - lps[n-1];
    }
};