// Problem Link : https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/


// Solution //
class Solution {
public:
    int maxScore;
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        maxScore = 0;
        int freq[26] = {0};
        for(auto &ch : letters) freq[ch-'a'] += 1;
        helper(words, score, freq, 0, 0);
        return maxScore;
    }

    void helper(vector<string> &words, vector<int> &letterScore, int freq[], int idx, int currScore){
        if( idx == words.size() ){
            maxScore = max(maxScore, currScore);
        } else{
            // Exclude //
            helper(words, letterScore, freq, idx+1, currScore);
            // Include //
            string &word = words[idx];
            int newScore = currScore;
            int f[26] = {0};
            for(auto &ch : word){
                if( ++f[ch-'a'] > freq[ch-'a'] ){
                    return;
                }
            } 
            // Updating the state of freq array //
            for(int i=0; i<26; i++) freq[i] -= f[i], newScore += (letterScore[i] * f[i]);
            helper(words, letterScore, freq, idx+1, newScore);
            // Bringing back to the old state //
            for(int i=0; i<26; i++) freq[i] += f[i];
        }
    }
};