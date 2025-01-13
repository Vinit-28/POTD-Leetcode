// Problem Link : https://leetcode.com/problems/minimum-length-of-string-after-operations/description/


// Solution //
class Solution {
public:
    int minimumLength(string s) {
        int hmap[26] = {0};
        int ans = 0;
        for(auto &ch : s){
            hmap[ch-'a'] += 1;
        }
        for(int i=0; i<26; i++){
            if( hmap[i] > 0 ){
                ans += ((hmap[i]&1)? 1 : 2);
            }
        }
        return ans;
    }
};