// Problem Link : https://leetcode.com/problems/permutation-in-string/description/


// Solution //
class Solution {
private:
    bool isWindowValid(int hmap1[], int hmap2[]){
        for(int i=0; i<26; i++){
            if( hmap1[i] != hmap2[i] ) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if( n1 > n2 ) return false;
        int hmap1[26] = {0};
        int hmap2[26] = {0};
        for(auto &ch : s1) hmap1[ch-'a'] += 1;
        for(int i=0; i<n1-1; i++) hmap2[s2[i]-'a'] += 1;
        for(int i=n1-1; i<n2; i++){
            hmap2[s2[i]-'a'] += 1;
            if( isWindowValid(hmap1, hmap2) ) return true;
            hmap2[s2[i-n1+1]-'a'] -= 1;
        }
        return false;
    }
};