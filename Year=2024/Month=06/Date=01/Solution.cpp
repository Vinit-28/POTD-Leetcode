// Problem Link : https://leetcode.com/problems/score-of-a-string/description/


// Solution //
class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        int n = s.length();
        for(int idx=1; idx<n; idx++){
            sum += abs(s[idx]-s[idx-1]);
        }
        return sum;
    }
};