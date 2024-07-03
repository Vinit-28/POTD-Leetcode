// Problem Link : https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/


// Solution //
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int k = 3; // Moves //
        int ans = INT_MAX;
        if( n<=4 ) return 0;
        sort(nums.begin(), nums.end());
        for(int leftMoves=0; leftMoves<=k; leftMoves++){
            int rightMoves = (k - leftMoves);
            int diff = nums[n-rightMoves-1] - nums[leftMoves];
            ans = min(ans, diff);
        }
        return ans;
    }
};