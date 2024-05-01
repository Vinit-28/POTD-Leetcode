// Problem Link : https://leetcode.com/problems/reverse-prefix-of-word/description/


// Solution //
class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans = "";
        bool reversed = false;
        for(auto &c : word){
            ans.push_back(c);
            if( c == ch && reversed == false ){
                reverse(ans.begin(), ans.end());
                reversed = true;
            }
        }
        return ans;
    }
};
