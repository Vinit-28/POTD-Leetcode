// Problem Link : https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/


// Solution //
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        // Declaration //
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> prefixSum = matrix;
        // Initializing the prefixSum //
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                prefixSum[i][j] += prefixSum[i][j-1];
            }
        }
        // Main Logic //
        for(int st=0;st<n;st++){
            for(int ed=st;ed<n;ed++){
                int sum = 0;
                map<int, int> mpp;
                mpp[0] = 1;
                for(int row=0;row<m;row++){
                    int ele = st==0? prefixSum[row][ed] : prefixSum[row][ed] - prefixSum[row][st-1];
                    sum += ele;
                    ans += mpp[sum - target];
                    mpp[sum] += 1;
                }
            }
        }
        return ans;
    }
};