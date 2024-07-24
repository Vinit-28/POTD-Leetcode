// Problem Link : https://leetcode.com/problems/sort-the-jumbled-numbers/description/


// Solution //
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        map<int, vector<int>> mpp;
        int idx = 0;
        // Mapping New Numbers //
        for(int i=0; i<n; i++){
            int newNum = getNewNum(mapping, nums[i]);
            mpp[newNum].push_back(i);
        }
        // Setting up the original numbers in the sorted order of new numbers //
        for(auto [num, indices] : mpp){
            for(auto &arrIdx: indices){
                ans[idx++] = nums[arrIdx];
            }
        }
        return ans;
    }

    // Method to make the new number as per the mapping of the digits //
    int getNewNum(vector<int>& mapping, int num){
        string strNum = to_string(num);
        int newNum = 0;
        for(auto &d : strNum){
            newNum = (newNum*10) + mapping[d-'0'];
        }
        return newNum;
    }
};