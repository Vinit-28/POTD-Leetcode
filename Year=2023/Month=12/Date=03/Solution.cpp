// Problem Link : https://leetcode.com/problems/minimum-time-visiting-all-points/description/


// Solution //
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        int x1 = points[0][0], y1 = points[0][1];
        for(int i=1;i<n;i++){
            int x2 = points[i][0], y2 = points[i][1];
            int steps = max(abs(x2-x1), abs(y2-y1));
            ans += steps;
            x1 = x2, y1 = y2;
        }
        return ans;
    }
};