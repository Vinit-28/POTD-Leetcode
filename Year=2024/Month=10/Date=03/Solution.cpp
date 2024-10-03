// Problem Link : https://leetcode.com/problems/make-sum-divisible-by-p/description/


// Solution //
using ll = long long;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int ans = n;
        unordered_map<int, int> modLastIdx;
        ll prefix[n];
        prefix[0] = nums[0];
        // Prefix Sum //
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        // Iterate from the right, store the latest idx for the mod //
        ll sum = 0;
        for(int i=n-1; i>=0; i--){
            ll leftSum = prefix[i];
            int mod = leftSum%p;
            int req = mod==0? 0 : p-mod;
            if( modLastIdx.find(req) != modLastIdx.end() ){
                int elesToRemove = n - (i+1 + (n-modLastIdx[req]));
                ans = min(ans, elesToRemove);
            }
            if( req == 0 ){
                int elesToRemove = n - i - 1;
                ans = min(ans, elesToRemove);
            }
            sum += nums[i];
            mod = sum%p;
            modLastIdx[mod] = i;
            if( mod == 0 ){
                int elesToRemove = n - (n-i);
                ans = min(ans, elesToRemove);
            }
        }
        return ans==n? -1 : ans;
    }
};