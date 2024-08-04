// Problem Link : https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/


// Solution //
class Solution {
public:
    using ll = long long;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<ll> arr;
        ll mod = 1e9+7;
        for(int i=0; i<n; i++){
            ll sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                arr.push_back(sum);
            }
        }
        sort(begin(arr), end(arr));
        ll ans = 0;
        for(int idx=0; idx<arr.size(); idx++){
            if( (idx+1) >= left && (idx+1) <= right ){
                ans = (ans + arr[idx])%mod;
            }
        }
        return ans;
    }
};