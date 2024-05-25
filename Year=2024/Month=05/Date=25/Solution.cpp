// Problem Link : https://leetcode.com/problems/word-break-ii/description/


// Solution //
class Solution {
public:
    vector<string> ans;
    set<string> dict;
    vector<string> wordBreak(string s, vector<string>& wordDict) {   
        ans.clear();
        dict = set<string>(wordDict.begin(), wordDict.end());
        helper(s, 0, "", "");
        return ans;
    }

    void helper(string s, int idx, string sentence, string word){
        if( idx == s.length() ){
            if( dict.find(word) != dict.end() ){
                ans.push_back(sentence + word);
            }
        } else{
            // Continue with the previous word //
            helper(s, idx+1, sentence, word+s[idx]);
            // Add a space //
            if( dict.find(word) != dict.end() ){
                string newWord = ""; newWord += s[idx];
                helper(s, idx+1, sentence+word+' ', newWord);
            }
        }
    }
};