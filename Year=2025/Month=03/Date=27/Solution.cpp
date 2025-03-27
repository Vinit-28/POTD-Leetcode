// Problem Link : https://leetcode.com/problems/minimum-index-of-a-valid-split/description/


// Solution //
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int x = nums[n-1];
        vector<int> suf(n, -1);
        unordered_map<int,int> mpp;
        for(int idx=n-1; idx>=0; idx--){
            if( ++mpp[nums[idx]] > mpp[x] ){
                x = nums[idx];
            }
            if( mpp[x] > ((n-idx)/2) ) suf[idx] = x;
        }
        mpp.clear();
        x = nums[0];
        for(int idx=0; idx<n-1; idx++){
            if( ++mpp[nums[idx]] > mpp[x] ){
                x = nums[idx];
            }
            if( mpp[x] > ((idx+1)/2) && x == suf[idx+1] ) return idx;
        }
        return -1;
    }
};