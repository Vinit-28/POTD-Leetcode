// Problem Link : https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/


// Solution //
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "", s2 = "";
        for(auto &w1 : word1){
            s1 += w1;
        }
        for(auto &w2 : word2){
            s2 += w2;
        }
        return s1 == s2;
    }
};