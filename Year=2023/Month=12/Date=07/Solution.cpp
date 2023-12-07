// Problem Link : https://leetcode.com/problems/largest-odd-number-in-string/description/

// Solution //
class Solution {
public:
    string largestOddNumber(string num) {
        int idx = -1, n = num.size();
        for(int i=0;i<n;i++){
            int digit = (num[i]-'0');
            if( digit&1 ){
                idx = i;
            }
        }
        return idx==-1? "" : num.substr(0, idx+1);
    }
};
