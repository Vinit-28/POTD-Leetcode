// Problem Link : https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/


// Solution //
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<long> dq; // Monotonic increasing order -- To find the left Minimum  Sum //
        int n = nums.size();
        int minWindow = INT_MAX;
        long prefixSum[n];
        prefixSum[0] = nums[0];
        // Finding the prefix sum //
        for(int idx=1; idx<n; idx++){
            prefixSum[idx] = prefixSum[idx-1] + nums[idx];
        }
        // Finding the answer //
        for(int idx=0; idx<n; idx++){
            long sumTillIdx = prefixSum[idx]; // Sum till current index //
            long rem = sumTillIdx - k; // Remaining value //
            // We just want to find the nearest value that is <= rem,
            // '=' because assuming rem + k = sumTillIdx. '<' because we want 
            // to consider the sum > k as well, so if we want sum > k then for
            // sure rem' = sumTillIdx - k'(k' > k) will always be < rem (rem' < rem).
            while( !dq.empty() && prefixSum[dq.front()] <= rem ){
                int window = idx - dq.front();
                minWindow = min(minWindow, window);
                dq.pop_front();
            }
            if( sumTillIdx >= k ){
                minWindow = min(minWindow, idx+1);
            }
            // Maintaining the monotonic increasing prefixSum order
            // as we want smallest prefixSum at the top of the deque.
            while( !dq.empty() && sumTillIdx <= prefixSum[dq.back()] ){
                dq.pop_back();
            }
            dq.push_back(idx);
        }
        return minWindow==INT_MAX? -1 : minWindow;
    }
};