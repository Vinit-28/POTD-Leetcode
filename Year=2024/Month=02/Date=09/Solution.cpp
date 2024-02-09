// Problem Link : https://leetcode.com/problems/largest-divisible-subset/description/


// Solution //
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answers;
        int maxSizeIdx = 0;
        for(int i=nums.size()-1;i>=0;i--){
            int idx = -1;
            for(int j=0;j<answers.size();j++){
                if( (answers[j].back()%nums[i] == 0) && (idx==-1 || answers[j].size() > answers[idx].size()) ){
                    idx = j;
                }
            }
            if( idx == -1 ){
                answers.push_back({nums[i]});
            } else{
                auto subset = answers[idx];
                subset.push_back(nums[i]);
                answers.push_back(subset);
            }

            if( answers.back().size() > answers[maxSizeIdx].size() ){
                maxSizeIdx = answers.size()-1;
            }
        }
        return answers[maxSizeIdx];
    }
};