// Problem Link : https://leetcode.com/problems/word-subsets/description/


// Solution //
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        int maxCharFreq[26] = {0};
        // Finding the max frequency for every character in words2 list //
        for(auto &word : words2){
            int hmap[26] = {0};
            for(auto &ch : word){
                maxCharFreq[ch-'a'] = max(maxCharFreq[ch-'a'], ++hmap[ch-'a']);
            }
        }
        // Finding the universal strings/words from words1 list //
        for(auto &word : words1){
            int hmap[26] = {0};
            for(auto &ch : word){
                hmap[ch-'a'] += 1;
            } 
            if( isStringUniversal(hmap, maxCharFreq) ){
                ans.push_back(word);
            }
        }
        return ans;
    }
private:
    bool isStringUniversal(int hmap[26], int maxCharFreq[26]){
        for(int chIdx=0; chIdx<26; chIdx++){
            if( maxCharFreq[chIdx] > hmap[chIdx] ){
                return false;
            }
        }
        return true;
    }
};