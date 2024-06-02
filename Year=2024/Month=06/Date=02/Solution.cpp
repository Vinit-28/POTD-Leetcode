// Problem Link : https://leetcode.com/problems/reverse-string/description/


// Solution //
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i=0,j=n-1; i<j; i++,j--){
            swap(s[i], s[j]);
        }
    }
};