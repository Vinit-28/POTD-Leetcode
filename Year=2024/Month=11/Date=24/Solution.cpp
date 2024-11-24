// Problem Link : https://leetcode.com/problems/maximum-matrix-sum/description/


// Solution //
using ll = long long;
class Solution {
public:
    ll maxMatrixSum(vector<vector<int>>& matrix) {
        ll ans = 0;
        ll mini = 1e9;
        int n = matrix.size();
        int negCount = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                negCount += (matrix[i][j] < 0);
                ans += abs(matrix[i][j]);
                mini = min(mini, (ll)abs(matrix[i][j]));
            }
        }
        if( negCount&1 ){
            ans -= (mini*2);
        }
        return ans;
    }
};