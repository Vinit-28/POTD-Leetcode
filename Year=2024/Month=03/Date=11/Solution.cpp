// Problem Link : https://leetcode.com/problems/custom-sort-string/description/


// Solution //
class Solution {
public:
    string getStr(char ch, int len){
        string str = "";
        for(int i=0;i<len;i++){
            str += ch;
        }
        return str;
    }

    string customSortString(string order, string s) {
        int freqMap[26] = {0};
        string ans = "";
        for(auto &ch : s){
            freqMap[ch-'a'] += 1;
        }
        for(auto &ch : order){
            ans += getStr(ch, freqMap[ch-'a']);
            freqMap[ch-'a'] = 0;
        }
        for(char ch='a';ch<='z';ch++){
            ans += getStr(ch, freqMap[ch-'a']);
        }
        return ans;
    }
};