// Problem Link : https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/


// Solution //
class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<char, int> mpp;
        mpp['a'] = 0, mpp['e'] = 1, mpp['i'] = 2, mpp['o'] = 3, mpp['u'] = 4;
        int val = 0, n = s.length();
        int maxLen = 0;
        int hmap[32]; memset(hmap, -1, sizeof(hmap));
        hmap[0] = 0;
        for(int i=0; i<n; i++){
            auto &ch = s[i];
            if( mpp.find(ch) != mpp.end() ){
                int mask = (1<<mpp[ch]);
                val ^= mask; // Toggling vowel respective bit //
                if( hmap[val] == -1 ) hmap[val] = i+1;
            }
            int len = i - hmap[val] + 1;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};