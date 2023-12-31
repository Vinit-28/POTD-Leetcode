// Problem Link : https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/


// Solution //
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int hmap[26]; memset(hmap, -1, sizeof(hmap));
        int n = s.length(), ans = -1;
        for(int i=0;i<n;i++){
            if( hmap[s[i]-'a'] == -1 ){
                hmap[s[i]-'a'] = i;
            } else{
                ans = max(ans, (i-hmap[s[i]-'a']-1));
            }
        }
        return ans;
    }
};