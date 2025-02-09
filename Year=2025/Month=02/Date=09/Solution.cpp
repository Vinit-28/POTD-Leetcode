// Problem Link : https://leetcode.com/problems/count-number-of-bad-pairs/description/


// Solution //
using ll = long long;
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        ll n = (ll) nums.size();
        ll total = (n*(n-1))/2;
        ll good = 0;
        unordered_map<ll, ll> mpp;
        for(int idx=0; idx<(int)n; idx++){
            good += mpp[nums[idx]-idx];
            mpp[-idx+nums[idx]] += 1;
        }
        return total - good;
    }
};