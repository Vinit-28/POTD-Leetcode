// Problem Link : https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/


// Solution -- Using PrefixSum & HashMap //
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        map<int, int> prefixSumMap;
        int sum = 0, n = nums.size(), ans = INT_MAX;
        int prefixSum[n];
        // Storing Prefix Sum //
        for(int i=0;i<n;i++){
            sum += nums[i];
            prefixSum[i] = sum;
            prefixSumMap[sum] = i;
        }
        // Finding the answer //
        for(int i=0;i<n;i++){
            // First Case leftmost to current index //
            if( prefixSum[i] == x ){
                ans = min(ans, i+1);
            }
            // Second Case current index to rightmost //
            if( i>0 && (prefixSum[n-1] - prefixSum[i-1]) == x ){
                ans = min(ans, n-i);
            }
            // Third Case current index to rightmost & some elements from left as well //
            if( i>0 ){
                int a = (prefixSum[n-1] - prefixSum[i-1]);
                int b = x - a;
                if( prefixSumMap.find(b) != prefixSumMap.end() && prefixSumMap[b] < i ){
                    ans = min(ans, (n-i) + (prefixSumMap[b]+1));
                }
            }
        }
        return ans==INT_MAX? -1 : ans;
    }
};



// Solution -- Using Only PrefixSum //
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size(), ans = INT_MAX;
        int prefixSum[n];
        // Storing Prefix Sum //
        for(int i=0;i<n;i++){
            sum += nums[i];
            prefixSum[i] = sum;
        }
        // Finding the answer //
        for(int i=0;i<n;i++){
            // First Case leftmost to current index //
            if( prefixSum[i] == x ){
                ans = min(ans, i+1);
            }
            // Second Case current index to rightmost //
            if( i>0 && (prefixSum[n-1] - prefixSum[i-1]) == x ){
                ans = min(ans, n-i);
            }
        }
        // Handling the edge case -- include elements from both sides left & right //
        int xDash = sum - x, maxElesInclude = 0, start = 1;
        sum = nums[1];
        for(int i=2;i<n;i++){
            sum += nums[i];
            while( sum > xDash && start <= i ){
                sum -= nums[start++];
            }
            if( sum == xDash ){
                maxElesInclude = max(maxElesInclude, i-start+1);
            }
        }
        ans = maxElesInclude == 0? ans : min(ans, n - maxElesInclude);
        return ans==INT_MAX? -1 : ans;
    }
};