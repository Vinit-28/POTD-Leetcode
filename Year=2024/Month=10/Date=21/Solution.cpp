// Problem Link : https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/


// Solution //
class Solution {
public:

    int maxUniqueSplit(string s) {
        int ans = 0;
        unordered_map<string, int> mpp;
        helper(s, 0, "", mpp, ans);
        return ans;
    }

    void helper(string &s, int idx, string sub, unordered_map<string, int>&mpp, int &ans){
        if(idx >= s.length()){
            mpp[sub] += 1;
            ans = max(ans, int(mpp.count("")? mpp.size()-1 : mpp.size()));
            if(--mpp[sub] == 0) mpp.erase(sub);
        } else{
            helper(s, idx+1, sub+s[idx], mpp, ans);

            mpp[sub] += 1;
            string newSub = ""; newSub += s[idx];
            helper(s, idx+1, newSub, mpp, ans);
            if(--mpp[sub]==0) mpp.erase(sub);
        }
    }
};