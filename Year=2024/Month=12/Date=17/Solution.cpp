// Problem Link : https://leetcode.com/problems/construct-string-with-repeat-limit/description/


// Solution //
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int hmap[26] = {0};
        string ans = "";
        for(auto &ch : s) hmap[ch-'a'] += 1;
        for(char maxCh='z'; maxCh>='a';){
            if( hmap[maxCh-'a'] == 0 ){
                maxCh--;
            } else{
                int takenCount = min(hmap[maxCh-'a'], repeatLimit);
                ans += repeatChar(maxCh, takenCount);
                hmap[maxCh-'a'] -= takenCount;
                if( hmap[maxCh-'a'] > 0 ){
                    char nextMaxCh = maxCh-1;
                    while( nextMaxCh >= 'a' && hmap[nextMaxCh-'a'] == 0 ){
                        nextMaxCh--;
                    }
                    if( nextMaxCh < 'a' ){
                        return ans;
                    } else{
                        ans += nextMaxCh;
                        hmap[nextMaxCh-'a'] -= 1;
                    }
                } 
            }
        }
        return ans;
    }
    
    string repeatChar(char ch, int times){
        string str = "";
        while( times-- > 0 ) str += ch;
        return str;
    }
};