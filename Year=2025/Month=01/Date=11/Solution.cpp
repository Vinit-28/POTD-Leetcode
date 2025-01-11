// Problem Link : https://leetcode.com/problems/construct-k-palindrome-strings/description/


// Solution //
class Solution {
public:
    bool canConstruct(string s, int k) {
        if( s.length() < k ) return false;
        int hmap[26] = {0};
        for(auto &ch : s) hmap[ch-'a'] += 1;
        int odds = 0;
        for(int i=0; i<26; i++) odds += (hmap[i]&1);
        return odds <= k;
    }
};