// Problem Link : https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/


// Solution //
class Solution {
public:
    int minSteps(string s, string t) {
        int hs[26] = {0}, ht[26] = {0};
        int n = s.length();
        int steps = 0;
        for(int i=0;i<n;i++){
            hs[s[i]-'a'] += 1;
            ht[t[i]-'a'] += 1;
        }
        for(int i=0;i<26;i++){
            steps += max(hs[i]-ht[i], 0);
        }
        return steps;
    }
};