// Problem Link : https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/


// Solution //
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int maxDiff = 0, n = points.size();
        for(int i=1;i<n;i++){
            int diff = points[i][0] - points[i-1][0];
            maxDiff = max(maxDiff, diff);
        }
        return maxDiff;
    }
};