// Problem Link : https://leetcode.com/problems/binary-subarrays-with-sum/description/


// Solution //
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> hmap;
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        hmap[0] = 1;
        for(int idx = 0; idx < n; idx++){
            sum += nums[idx];
            int diff = sum - goal;
            ans += hmap[diff];
            hmap[sum]++;
        }
        return ans;
    }
};