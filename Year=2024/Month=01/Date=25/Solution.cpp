// Problem Link : https://leetcode.com/problems/longest-common-subsequence/description/


// Solution //
class Solution {
public:
    vector<vector<int>> dp;
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size();
        int size2 = text2.size();
        dp = vector<vector<int>>(size1, vector<int>(size2, -1));
        return helper(text1, text2, size1, size2, 0, 0);
    }

    int helper(string &text1, string &text2, int &size1, int &size2, int idx1, int idx2){
        if( idx1 >= size1 || idx2 >= size2 ){
            return 0;
        } else if( dp[idx1][idx2] == -1 ){
            if( text1[idx1] == text2[idx2] ){
                dp[idx1][idx2] = 1+helper(text1, text2, size1, size2, idx1+1, idx2+1);
            } else{
                int choice1 = helper(text1, text2, size1, size2, idx1+1, idx2);
                int choice2 = helper(text1, text2, size1, size2, idx1, idx2+1);
                dp[idx1][idx2] = max(choice1, choice2);
            }
        }
        return dp[idx1][idx2];
    }
};