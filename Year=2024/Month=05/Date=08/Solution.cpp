// Problem Link : https://leetcode.com/problems/relative-ranks/description/


// Solution //
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<vector<int>> scores;
        int n = score.size();
        vector<string> ans(n);
        vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        for(int idx=0; idx<n; idx++) scores.push_back({score[idx], idx});
        sort(scores.begin(), scores.end(), greater<vector<int>>());

        for(int idx=0; idx<n; idx++){
            int scIdx = scores[idx][1];
            if( idx >= medals.size() ){
                ans[scIdx] = to_string(idx+1);
            } else{
                ans[scIdx] = medals[idx];
            }
        }
        return ans;
    }
};
