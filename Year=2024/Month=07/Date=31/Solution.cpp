// Problem Link : https://leetcode.com/problems/filling-bookcase-shelves/description/


// Solution //
class Solution {
public:
    int shelfWidth;
    int dp[1001][1001];
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        this->shelfWidth = shelfWidth;
        memset(dp, -1, sizeof(dp));
        return helper(books, 1, 0, 0, shelfWidth-books[0][0]);
    }

    int helper(vector<vector<int>> &books, int idx, int startIdx, int maxIdx, int sw){
        if( idx == books.size() ){
            return books[maxIdx][1];
        } else if( dp[idx][startIdx] == -1 ){
            int inc = 1e9, exc = 1e9;
            // Include //
            if( sw >= books[idx][0] ){
                int nextMaxIdx = (books[maxIdx][1] < books[idx][1]? idx : maxIdx);
                inc = helper(books, idx+1, startIdx, nextMaxIdx, sw-books[idx][0]);
            }
            // Exclude //
            exc = books[maxIdx][1] + helper(books, idx+1, idx, idx, shelfWidth-books[idx][0]);
            dp[idx][startIdx] = min(inc, exc);
        }
        return dp[idx][startIdx];
    }
};