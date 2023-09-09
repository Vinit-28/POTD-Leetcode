// Problem Link : https://leetcode.com/problems/combination-sum-iv/


// Solution //
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        unsigned int n = nums.size(), dp[target+1][n], sum=0;
        
        for(unsigned int i=1;i<=target;i++){
            sum = 0;
            for(unsigned int j=0;j<n;j++){
                
                if( i == nums[j] ) sum += 1;
                else if ( nums[j] < i ) sum += dp[i-nums[j]][n-1];
                
                dp[i][j] = sum;
            }
        }
        return dp[target][n-1];
    }
};