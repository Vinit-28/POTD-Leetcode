// Problem Link : https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/


// Solution //
class Solution {
public:
    bool isPalindrome(string &s){
        int i = 0, j = s.length()-1;
        while( i<j ){
            if( s[i++] != s[j--] ) return false;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for(auto &word : words){
            if( isPalindrome(word) ) return word;
        }
        return "";
    }
};