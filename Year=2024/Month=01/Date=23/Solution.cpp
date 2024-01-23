// Problem Link : https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/


// Solution //
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        helper(arr, 0, "", ans);
        return ans;
    }

    void helper(vector<string> &arr, int idx, string s, int &ans){
        if( idx >= arr.size() ){
            int size = s.size();
            ans = max(ans, size);
        } else{
            // exclude //
            helper(arr, idx+1, s, ans);
            // include //
            if( isValid(s, arr[idx]) ){
                helper(arr, idx+1, s+arr[idx], ans);
            }
        }
    }

    bool isValid(string &s1, string &s2){
        int h1[26] = {0}, h2[26] = {0};
        for(auto &ch : s1) if( ++h1[ch-'a'] > 1 ) return false;
        for(auto &ch : s2) if( ++h2[ch-'a'] > 1 ) return false;
        for(int i=0;i<26;i++){
            if( h1[i] > 0 && h2[i] > 0 ) return false;
        }
        return true;
    }
};