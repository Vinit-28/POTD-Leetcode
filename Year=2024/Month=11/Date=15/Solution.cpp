// Problem Link : https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/description/


// Solution //
class Solution {
private:
    bool isValid(int n, vector<int> &arr, int prefix[], int toRemove){
        for(int from=0; from<=(n-toRemove); from++){
            int to = from + toRemove;
            int leftSum = from==0? -1 : prefix[from-1];
            int rightSum = to==n? -1 : prefix[n-1] - prefix[to];
            int leftEles = from;
            int rightEles = n-to;
            int leftLastEle = from==0? -1e9 : arr[from-1];
            int rightFirstEle = to==n? 1e9 : arr[to];
            if( leftSum == leftEles-1 && rightSum == rightEles-1 && leftLastEle <= rightFirstEle ){
                return true;
            }
        }
        return false;
    }
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int prefix[n];
        // Prefix Sum //         
        prefix[0] = 0;
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + (arr[i] >= arr[i-1]);
        }
        // Binary Search on Answer //
        int l = 0, u = n-1;
        int ans = u;
        while( l<=u ){
            int mid = (l+u)/2;
            if( isValid(n, arr, prefix, mid) ){
                ans = mid;
                u = mid-1;
            } else{
                l = mid+1;
            }
        }
        return ans;
    }
};