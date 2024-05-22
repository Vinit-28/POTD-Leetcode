// Problem Link : https://leetcode.com/problems/palindrome-partitioning/description/


// Solution //
class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome[16][16];

    vector<vector<string>> partition(string s) {
        ans.clear();
        memset(isPalindrome, false, sizeof(isPalindrome));
        int n = s.length();
        vector<string> strings;
        for(int i=0; i<n; i++){
            for(int r=0,c=i; c<n; r++,c++){
                if( r==c ) isPalindrome[r][c] = true;
                else if( s[r] == s[c] ) isPalindrome[r][c] = ((r+1) > (c-1) || isPalindrome[r+1][c-1]);
            }
        }    
        helper(s, 0, 0, strings);
        return ans;
    }

    void helper(string &s, int start, int end, vector<string> &strings){
        if( end == s.length() ){
            if( start == end ){
                ans.push_back(strings);
            }
        } else{
            // String ends at current index //
            if( isPalindrome[start][end] ){
                strings.push_back(s.substr(start, (end-start+1)));
                helper(s, end+1, end+1, strings);
                strings.pop_back();
            }
            // String continues //
            helper(s, start, end+1, strings);
        }
    }
};