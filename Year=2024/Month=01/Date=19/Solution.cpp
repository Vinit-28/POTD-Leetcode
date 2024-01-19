// Problem Link : https://leetcode.com/problems/minimum-falling-path-sum/description/


// Solution //
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int minVal = min({getValue(matrix[i+1], n, j-1), getValue(matrix[i+1], n, j), getValue(matrix[i+1], n, j+1)});
                matrix[i][j] += minVal;
            }
        }
        return *min_element(matrix[0].begin(), matrix[0].end());
    }

    int getValue(vector<int> &arr, int &n, int idx){
        if( idx < 0 || idx >= n ) return INT_MAX;
        return arr[idx];
    }
};