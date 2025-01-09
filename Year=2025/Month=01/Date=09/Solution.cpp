// Problem Link : https://leetcode.com/problems/counting-words-with-a-given-prefix/description/


// Solution //
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(auto &word : words){
            count += startswith(word, pref);
        }
        return count;
    }
private:
    bool startswith(string s1, string s2){
        int n1 = s1.length();
        int n2 = s2.length();
        if( n1 < n2 ) return false;
        int i = 0, j = 0;
        while( j<n2 ){
            if( s1[i++] != s2[j++] ){
                return false;
            }
        }
        return true;
    }
};