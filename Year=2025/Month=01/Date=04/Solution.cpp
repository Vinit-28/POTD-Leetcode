// Problem Link : https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/


// Solution //
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int ans = 0;
        vector<vector<int>> charsFreqs(n, vector<int>(26, 0));
        vector<pair<int,int>> firstAndLastOccur(26, pair<int,int>(-1, -1));
        // PrefixSum Calculation //
        charsFreqs[0][s[0]-'a'] += 1;
        firstAndLastOccur[s[0]-'a'].first = firstAndLastOccur[s[0]-'a'].second = 0; 
        for(int idx=1; idx<n; idx++){
            for(int chIdx=0; chIdx<26; chIdx++){
                charsFreqs[idx][chIdx] = charsFreqs[idx-1][chIdx];
            }
            charsFreqs[idx][s[idx]-'a'] += 1;
            auto &indexPair = firstAndLastOccur[s[idx]-'a'];
            if( indexPair.first == -1 ) indexPair.first = idx;
            indexPair.second = idx;
        }
        // Calculating answer //
        for(int chIdx=0; chIdx<26; chIdx++){
            auto &indexPair = firstAndLastOccur[chIdx];
            if( indexPair.first != indexPair.second ){
                int l = indexPair.first;
                int r = indexPair.second;
                int uniqueCharsCount = getUniqueCharsCountInRange(charsFreqs, l+1, r-1);
                ans += uniqueCharsCount;
            }
        }
        return ans;
    }

private:
    int getUniqueCharsCountInRange(vector<vector<int>> &charsFreqs, int l, int r){
        int uniqueCharsCount = 0;
        for(int chIdx=0; chIdx<26; chIdx++){
            int freq = l==0? charsFreqs[r][chIdx] : charsFreqs[r][chIdx] - charsFreqs[l-1][chIdx];
            uniqueCharsCount += (freq > 0);
        }
        return uniqueCharsCount;
    }
};