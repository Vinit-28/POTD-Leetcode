// Problem Link : https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/


// Solution //
class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int count = 0;
        for(int i=0; i<n; i+=2){
            count += (s[i] != s[i+1]);
        }
        return count;
    }
};