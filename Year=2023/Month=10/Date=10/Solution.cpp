// Problem Link : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/description/


// Solution //
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        sort(nums.begin(), nums.end());
        vector<int> uniqueSortedArr;
        uniqueSortedArr.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if( uniqueSortedArr.back() != nums[i] ){
                uniqueSortedArr.push_back(nums[i]);
            }
        }
        int size = uniqueSortedArr.size(), diff = n-1;
        for(int i=0;i<size;i++){
            int pos = lower_bound(uniqueSortedArr.begin()+i+1, uniqueSortedArr.end(), uniqueSortedArr[i]+diff) - uniqueSortedArr.begin();
            if( pos >= size ){
                ans = min(ans, n-(size-i));
            } else if( uniqueSortedArr[pos] != (uniqueSortedArr[i] + diff) ){
                ans = min(ans, n-(pos-i));
            } else{
                ans = min(ans, n-(pos-i+1));
            }
        }
        return ans;
    }
};