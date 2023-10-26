// Problem Link : https://leetcode.com/problems/binary-trees-with-factors/description/


// Solution //
class Solution {
public:
    long M = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size(), dp[n], ans = 0;
        sort(arr.begin(), arr.end());

        for(int i=0;i<n;i++){
            dp[i] = 1;
            int l = 0, r = i-1;
            while( l<=r ){
                int div = (arr[i]/arr[l]);
                if( arr[i]%arr[l]!=0 || div > arr[r] ){
                    l += 1;
                } else if( div < arr[r] ){
                    r -= 1;
                } else{
                    int combs = multiply(dp[l], dp[r]);
                    dp[i] = add(dp[i], combs);
                    dp[i] = l==r? dp[i] : add(dp[i], combs);
                    l += 1, r -= 1;
                }
            }
            ans = add(ans, dp[i]);
        }
        return ans;
    }

    int multiply(int a, int b){
        return ((a%M) * (b%M))%M;
    }

    int add(int a, int b){
        return ((a%M) + (b%M))%M;
    }
};