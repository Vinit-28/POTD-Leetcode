// Problem Link : https://leetcode.com/problems/grid-game/description/


// Solution //
using ll = long long;
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        ll ans = LLONG_MAX;
        ll totalSum1 = accumulate(begin(grid[0]), end(grid[0]), ll(0));
        ll totalSum2 = accumulate(begin(grid[1]), end(grid[1]), ll(0));
        int n = grid[0].size();
        ll sum1 = 0;
        ll sum2 = 0;
        for(int idx=0; idx<n; idx++){
            sum1 += grid[0][idx];
            sum2 += grid[1][idx];
            ll r1 = sum1 + (totalSum2 - sum2 + grid[1][idx]);
            ll r2a = totalSum1 - sum1;
            ll r2b = sum2 - grid[1][idx];
            ll r2 = max(r2a, r2b);
            // cout<<"R1 "<<r1<<" :: "<<"R2 ("<<r2a<<","<<r2b<<")"<<endl;
            ans = min(ans, r2);
        }
        return ans;
    }
};