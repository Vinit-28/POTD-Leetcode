// Problem Link : https://leetcode.com/problems/count-the-number-of-fair-pairs/description/


// Solution //
using ll = long long;
class Solution {
public:
    ll countFairPairs(vector<int>& nums, int lower, int upper) {
        ll ans = 0;
        sort(begin(nums), end(nums));
        int n = nums.size();
        for(int idx=0; idx<n; idx++){
            int sum, leftIdx, rightIdx;
            sum = upper - nums[idx];
            rightIdx = upper_bound(begin(nums), end(nums), sum) - begin(nums);
            sum = lower - nums[idx];
            leftIdx = lower_bound(begin(nums), end(nums), sum) - begin(nums);
            ans += max(0, rightIdx-max(leftIdx, idx+1));
        }
        return ans;
    }
};