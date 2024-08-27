// Problem Link : https://leetcode.com/problems/maximum-number-of-points-with-cost/description/



// Solution //
class Solution {
public:
    using ll = long long;
    ll maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        ll dp[m][n];
        memset(dp, 0, sizeof(dp));
        // Initializing the first row //
        for(int i=0; i<n; i++) dp[0][i] = points[0][i];
        // DP //
        for(int row=1; row<m; row++){
            // Front //
            dp[row][0] = max(dp[row][0], points[row][0] + dp[row-1][0]);
            ll addOnVal = dp[row-1][0];
            for(int col=1; col<n; col++){
                addOnVal -= 1;
                addOnVal = max(addOnVal, (ll)dp[row-1][col]);
                ll val = addOnVal + points[row][col];
                dp[row][col] = max(dp[row][col], val);
            }
            // Back //
            dp[row][n-1] = max(dp[row][n-1], points[row][n-1] + dp[row-1][n-1]);
            addOnVal = dp[row-1][n-1];
            for(int col=n-2; col>=0; col--){
                addOnVal -= 1;
                addOnVal = max(addOnVal, (ll)dp[row-1][col]);
                ll val = addOnVal + points[row][col];
                dp[row][col] = max(dp[row][col], val);
            }
        }
        return *max_element(dp[m-1], dp[m-1]+n);
    }
};