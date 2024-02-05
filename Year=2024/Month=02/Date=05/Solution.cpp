// Problem Link : https://leetcode.com/problems/first-unique-character-in-a-string/description/


// Solution //
class Solution {
public:
    int firstUniqChar(string s) {
        int hmap[26] = {0};
        int n = s.length();
        for(auto &ch : s) hmap[ch-'a'] += 1;
        for(int i=0;i<n;i++) if( hmap[s[i]-'a'] == 1 ) return i;
        return -1; 
    }
};