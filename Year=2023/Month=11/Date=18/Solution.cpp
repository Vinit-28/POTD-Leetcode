// Problem Link : https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/


// Solution //
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, ans = 0;
        long sum = 0;
        for(int i=0;i<n;i++){
            long target = nums[i];
            sum += target;
            while( (((i-left+1)*target)-sum) > k ){
                sum -= nums[left++];
            }
            ans = max(ans, (i-left+1));
        }
        return ans;
    }
};