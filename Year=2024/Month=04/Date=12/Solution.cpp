// Problem Link : https://leetcode.com/problems/trapping-rain-water/description/


// Solution //
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = height[0], rightMax = height[n-1];
        int left = 0, right = n-1;
        int ans = 0;
        while( left < right ){
            if( height[left] <= height[right] ){
                leftMax = max(leftMax, height[++left]);
                ans += (leftMax - height[left]);
            } else{
                rightMax = max(rightMax, height[--right]);
                ans += (rightMax - height[right]);
            }
        }
        return ans;
    }
};