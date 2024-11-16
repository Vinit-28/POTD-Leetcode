// Problem Link : https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i//description/


// Solution //
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix[n];
        vector<int> ans;
        prefix[0] = 0;
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + (nums[i] == nums[i-1]+1);
        }
        
        for(int from=0; from<=n-k; from++){
            int to = from + k - 1;
            int sum = prefix[to] - prefix[from];
            if( sum == k-1 ) ans.push_back(nums[to]);
            else ans.push_back(-1);
        }
        return ans;
    }
};