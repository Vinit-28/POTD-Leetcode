// Problem Link : https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/


// Solution -- Recursion + Memoization (DP) //
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> arr;
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<=n;i++){
            arr.push_back({max(0, i-ranges[i]), min(n, i+ranges[i])});
        }
        sort(arr.begin(), arr.end());
        int res = helper(arr, n, 0, 0, dp);
        return res==INT_MAX? -1 : res;
    }

    int helper(vector<vector<int>> &arr, int &n, int idx, int boundary, int dp[]){
        if( boundary >= n ){
            return 0;
        } else if( idx >= arr.size() ){
            return INT_MAX;
        } else{
            if( boundary < arr[idx][0] ) return INT_MAX;
            int exclude = helper(arr, n, idx+1, boundary, dp);
            if( dp[idx] == -1 ){
                int res = helper(arr, n, idx+1, arr[idx][1], dp);
                int include = res==INT_MAX? INT_MAX : res+1;
                dp[idx] = include;
            }
            return min(dp[idx], exclude);
        }
        return -1;
    }
};



// Solution -- Greedy //
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> arr;
        int ans = 1, prevIdx = 0, idx = 1;
        for(int i=0;i<=n;i++){
            arr.push_back({max(0, i-ranges[i]), min(n, i+ranges[i])});
        }
        sort(arr.begin(), arr.end());
        while( idx <= n ){
            if( arr[idx][0] == arr[prevIdx][0] && arr[idx][1] > arr[prevIdx][1] ){
                prevIdx = idx++;
            } else if( arr[idx][0] > arr[prevIdx][0] && arr[idx][0] <= arr[prevIdx][1] && arr[idx][1] >= arr[prevIdx][1] ){
                int maxIdx = idx;
                for(int i=idx+1; i<=n; i++){
                    if( arr[i][0] > arr[prevIdx][0] && arr[i][0] <= arr[prevIdx][1] ){
                        if( arr[i][1] > arr[maxIdx][1] )
                            maxIdx = i;
                    } else {
                        break;
                    }
                }
                ans += 1;
                prevIdx = maxIdx;
                idx = maxIdx+1;
            } else if( arr[idx][0] > arr[prevIdx][1] ){
                return -1;
            } else{
                idx += 1;
            }
            if( arr[prevIdx][1] >= n ){
                return ans;
            }
        }
        return -1;
    }
};