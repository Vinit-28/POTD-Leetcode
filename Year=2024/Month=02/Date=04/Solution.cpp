// Problem Link : https://leetcode.com/problems/minimum-window-substring/description/


// Solution //
class Solution {
public:
    string minWindow(string s, string t) {
        int mapt[256] = {0}, maps[256] = {0};
        int charsCovered = 0;
        int minWind = INT_MAX, left = 0;
        int tLen = t.length(), sLen = s.length();
        int start = -1;
        for(auto &ch : t) mapt[ch] += 1;

        for(int i=0;i<sLen;i++){
            if( ++maps[s[i]] <= mapt[s[i]] ){
                charsCovered += 1;
            }
            if( charsCovered == tLen ){
                while( maps[s[left]] > mapt[s[left]] ){
                    maps[s[left++]] -= 1;
                }
                if( minWind > (i-left+1) ){
                    minWind = i-left+1;
                    start = left;
                }
            }
        }   
        return start==-1? "" : s.substr(start, minWind);
    }
};