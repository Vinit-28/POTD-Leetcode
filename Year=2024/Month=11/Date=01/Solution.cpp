// Problem Link : https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/


// Solution //
class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int n = s.length();
        int f = 1;
        ans += s[0];
        for(int i=1; i<n; i++){
            if( s[i] != s[i-1] ){
                f = 0;
            }
            f += 1;
            if( f <= 2 ) ans += s[i];
        }
        return ans;
    }
};