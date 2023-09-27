// Problem Link : https://leetcode.com/problems/decoded-string-at-index/description/


// Solution //
class Solution {
public:
    bool isAplaphabet(char &ch){
        return (ch >= 'a' && ch <= 'z');
    }

    string decodeAtIndex(string &s, int k) {
        long long idx = 0;
        char prevChar;
        for(auto &ch : s){
            if( isAplaphabet(ch) ){
                idx += 1;
            } else{
                int d = (ch - '0');
                long long end = idx * d;
                if( k >= idx && k <= end ){
                    if ( k%idx == 0 ){
                        string ans = ""; ans += prevChar;
                        return ans;
                    } else{
                        return decodeAtIndex(s, k%idx);
                    }
                } else{
                    idx = end;
                }
            }
            if( idx == k ){
                string ans = ""; ans += ch;
                return ans;
            }
            prevChar = (isAplaphabet(ch))? ch : prevChar;
        }
        return "0";
    }
};