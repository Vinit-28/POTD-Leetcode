// Problem Link : https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/


// Solution //
class Solution {
private:
    vector<vector<int>> dp;
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        map<int,int> mpp;
        int n = arr.size();
        int maxAns = 0;
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        for(int idx=0; idx<n; idx++) mpp[arr[idx]] = idx;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int sum = (arr[i] + arr[j]);
                if( mpp.count(sum) ){
                    maxAns = max(maxAns, helper(arr, j, i, mpp));
                }
            }
        }
        return maxAns==0? 0 : maxAns+1;
    }

private:
    int helper(vector<int> &arr, int idx, int prev, map<int,int> &mpp){
        if( dp[idx][prev]==-1 ){
            int sum = arr[idx] + arr[prev];
            if( mpp.count(sum) ){
                dp[idx][prev] = helper(arr, mpp[sum], idx, mpp)+1;
            } else{
                dp[idx][prev] = 1;
            }
        }
        return dp[idx][prev];
    }
};