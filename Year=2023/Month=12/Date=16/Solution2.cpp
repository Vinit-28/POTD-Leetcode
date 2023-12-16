// Problem Link : https://leetcode.com/problems/valid-anagram/description/


// Solution //
class Solution {
public:
    bool isAnagram(string s, string t) {
        int hmapS[26] = {0}, hmapT[26] = {0};
        for(auto &ch : s) hmapS[ch-'a'] += 1;
        for(auto &ch : t) hmapT[ch-'a'] += 1;
        for(int i=0;i<26;i++){
            if( hmapS[i] != hmapT[i] ) return false;
        }
        return true;
    }
};