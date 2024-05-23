// Problem Link : https://leetcode.com/problems/the-number-of-beautiful-subsets/description/


// Solution //
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int mpp[1001];
        sort(nums.begin(), nums.end());
        memset(mpp, 0, sizeof(mpp));
        return helper(nums, k, 0, mpp)-1;
    }

    int helper(vector<int> &nums, int &k, int idx, int mpp[1001]){
        if( idx >= nums.size() ){
            return 1;
        } else{
            int count = 0;
            // Include //
            if( (nums[idx]-k) <= 0 || mpp[nums[idx]-k] == 0 ){
                mpp[nums[idx]] += 1;
                count += helper(nums, k, idx+1, mpp);
                mpp[nums[idx]] -= 1;
            }
            // Exclude //
            count += helper(nums, k, idx+1, mpp);
            return count;
        }
    }
};