// Problem Link : https://leetcode.com/problems/count-elements-with-maximum-frequency/description/


// Solution //
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> h;
        int maxi = 0;
        int ans = 0;
        for(auto &ele : nums){
            maxi = max(maxi, ++h[ele]);
        }
        for(auto &p : h){
            ans += p.second==maxi? p.second : 0;
        }
        return ans;
    }
};