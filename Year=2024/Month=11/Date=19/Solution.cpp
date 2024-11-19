// Problem Link : https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/


// Solution //
using ll = long long;
class Solution {
public:
    ll maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll maxSum = 0;
        ll windowSum = 0;
        unordered_set<int> st;
        // First Window Sum //
        for(int idx=0; idx<k; idx++) windowSum += nums[idx];
        // Finding the longest window starting with idx left having only unique elements //
        int right = 0;
        for(int left=0; left<=n-k; left++){
            while( right < n && !st.count(nums[right]) ){
                st.insert(nums[right]);
                right += 1;
            }
            int windowLen = right - left;
            if( windowLen >= k ){
                maxSum = max(maxSum, windowSum);
            }
            windowSum -= nums[left];
            windowSum += left+k<n? nums[left+k] : 0;
            st.erase(nums[left]);
        }
        return maxSum;
    }
};