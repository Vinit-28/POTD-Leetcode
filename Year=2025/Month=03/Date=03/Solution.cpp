// Problem Link : https://leetcode.com/problems/partition-array-according-to-given-pivot/description/


// Solution //
class Solution {
public:
    vector<int> pivotArray(vector<int> &nums, int pivot) {
        int n = nums.size();
        vector<int> res(n, pivot);
        
        for(int i=0,idx=0; i<n; i++){
            if( nums[i] < pivot ){
                res[idx++] = nums[i];
            }
        }
        for(int i=n-1,idx=n-1; i>=0; i--){
            if( nums[i] > pivot ){
                res[idx--] = nums[i];
            }
        }
        return res;
    }
};