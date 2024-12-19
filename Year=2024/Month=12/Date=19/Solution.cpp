// Problem Link : https://leetcode.com/problems/max-chunks-to-make-sorted/description/


// Solution //
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int mpp[11];
        int n = arr.size();
        for(int i=0; i<n; i++){
            mpp[arr[i]] = i;
        }
        return helper(arr, mpp, 0);
    }
    
    int helper(vector<int> &arr, int mpp[], int num){
        if( num >= arr.size() ) return 0;
        if( arr[num] == num ) return 1 + helper(arr, mpp, num+1);
        int idx = num;
        int maxPos = mpp[num];
        while( idx <= maxPos ){
            maxPos = max(maxPos, mpp[idx]);
            idx += 1;
        }
        return 1 + helper(arr, mpp, idx);
    }
};