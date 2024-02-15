// Problem Link : https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/


// Solution //
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0, sum = 0;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++){
            if( sum > nums[i] && i >= 2 ){
                ans = max(ans, sum + nums[i]);
            }
            sum += nums[i];
        }
        return ans==0? -1 : ans;
    }
};
