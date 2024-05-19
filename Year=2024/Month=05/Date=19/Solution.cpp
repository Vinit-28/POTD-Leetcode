// Problem Link : https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/


// Solution //
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans = 0;
        int n = nums.size();
        vector<int> idxsToIncre;
        for(int i=0; i<n; i++){
            int value = nums[i];
            if( value < (value xor k) ){
                idxsToIncre.push_back(i);
            }
            ans += value;
        }
        if( idxsToIncre.size()&1 ){
            int minIncreIdx = idxsToIncre[0], minIncre = (nums[idxsToIncre[0]] xor k);
            long long sum = 0;
            // Finding the minimum one //
            for(auto &idx : idxsToIncre){
                int value = nums[idx];
                if( (value xor k) < minIncre ){
                    minIncre = (value xor k);
                    minIncreIdx = idx;
                }
            }
            // Updating all except the minimum one //
            for(auto &idx : idxsToIncre){
                if( idx != minIncreIdx ) nums[idx] = nums[idx] xor k;
            }
            // Caluclating the total sum //
            for(auto &value : nums) sum += value;
            ans = max(ans, sum);
            // Finding a potential pair for the minimum one //
            for(int i=0;i<n;i++){
                if( i != minIncreIdx ){
                    auto newSum = sum - (nums[i] - (nums[i] xor k)) + ((nums[minIncreIdx] xor k) - nums[minIncreIdx]);
                    ans = max(ans, newSum);
                }
            }

        } else{
            long long sum = 0;
            for(auto &idx : idxsToIncre){
                nums[idx] = nums[idx] xor k;
            }
            for(auto &value : nums) sum += value;
            ans = max(ans, sum);
        }
        return ans;
    }
};