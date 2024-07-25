// Problem Link : https://leetcode.com/problems/sort-an-array/description/


// Solution //
class Solution {
public:
    void mergeArray(vector<int> &nums, int l1, int u1, int l2, int u2){
        int i=l1, j=l2;
        vector<int> arr;
        while( i<=u1 || j<=u2 ){
            if( j>u2 || (i<=u1 && nums[i] <= nums[j]) ){
                arr.push_back(nums[i++]);
            } else{
                arr.push_back(nums[j++]);
            }
        }
        i=l1;
        for(auto &ele : arr){
            nums[i++] = ele;
        }
    }

    void mergeSort(vector<int> &nums, int l, int u){
        if( l < u ){
            int mid = (l+u)/2;
            mergeSort(nums, l, mid);
            mergeSort(nums, mid+1, u);
            mergeArray(nums, l, mid, mid+1, u);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};