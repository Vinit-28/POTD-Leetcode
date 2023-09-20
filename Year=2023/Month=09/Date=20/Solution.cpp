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



// Solution -- Using Sliding Window //
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size();
        // Making Sum //
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        // Finding the maximum no of elements to sum to find the x'(sum - x) //
        int xDash = sum - x, maxElesInclude = 0, start = 0;
        sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            while( sum > xDash && start <= i ){
                sum -= nums[start++];
            }
            if( sum == xDash ){
                maxElesInclude = max(maxElesInclude, i-start+1);
            }
        }
        return maxElesInclude==0? -1 : n-maxElesInclude;
    }
};