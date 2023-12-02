// Problem Link : https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/


// Solution //
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int charsMap[26] = {0};
        int len = 0;
        for(auto &ch : chars){
            charsMap[ch-'a'] += 1;
        }
        for(auto &word : words){
            int wordCharsMap[26] = {0};
            bool consider = true;
            for(auto &ch : word){
                wordCharsMap[ch-'a'] += 1;
            }
            for(int i=0;i<26;i++){
                if( wordCharsMap[i] > charsMap[i] ){
                    consider = false;
                    break;
                }
            }
            if( consider ){
                len += word.size();
            }
        }
        return len;
    }
};