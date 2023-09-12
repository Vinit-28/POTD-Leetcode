// Problem Link : https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/


// Solution //
class Solution {
public:
    int minDeletions(string s) {
        map<char, int> freq;
        map<int, bool> freqOfFreqs;
        int deletions = 0;

        // Count Frequencies //
        for(auto &ch : s){
            freq[ch] += 1;
        }
        // Storing the Frequencies //
        for(auto &p : freq){
            int frequency = p.second;
            while( frequency > 0 && freqOfFreqs.find(frequency) != freqOfFreqs.end() ){
                frequency -= 1;
                deletions += 1;
            }
            if( frequency ){
                freqOfFreqs[frequency] = true;
            }
        }
        return deletions;
    }
};