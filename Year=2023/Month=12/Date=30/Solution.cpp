// Problem Link : https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/description/


// Solution //
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int totalWords = 0;
        int charMap[26] = {0};
        for(auto &word : words){
            for(auto &ch : word){
                charMap[ch-'a'] += 1;
            }
            totalWords += 1;
        }
        for(int i=0;i<26;i++){
            if( charMap[i]%totalWords ){
                return false;
            }
        }
        return true;
    }
};
