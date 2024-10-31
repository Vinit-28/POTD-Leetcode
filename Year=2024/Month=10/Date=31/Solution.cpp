// Problem Link : https://leetcode.com/problems/minimum-total-distance-traveled/description/


// Solution //
using ll = long long;
class Solution {
private:
    vector<vector<ll>> dp;
public:
    ll minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int> factories;
        for(auto &v : factory){
            int p = v[0], c = v[1];
            for(int i=0; i<c; i++) factories.push_back(p);
        }  
        sort(begin(robot), end(robot));
        sort(begin(factories), end(factories));
        int rs = robot.size();
        int fs = factories.size();
        ll dp[rs+1][fs+1];
        // Base Case //
        for(int i=0; i<rs; i++) dp[i][fs] = 1e16; 
        for(int j=0; j<=fs; j++) dp[rs][j] = 0;

        for(int r=rs-1; r>=0; r--){
            for(int f=fs-1; f>=0; f--){
                // Consider //
                ll consider = abs(robot[r] - factories[f]) + dp[r+1][f+1];
                // Don't Consider //
                ll dConsider = dp[r][f+1];
                dp[r][f] = min(consider, dConsider);
            }
        }
        return dp[0][0];
    }
};