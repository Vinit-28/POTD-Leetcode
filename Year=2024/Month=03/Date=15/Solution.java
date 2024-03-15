// Problem Link : https://leetcode.com/problems/product-of-array-except-self/description/


// Solution //
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        ans[0] = nums[0];
        // Prefix //
        for(int idx=1; idx<n; idx++){
            ans[idx] = nums[idx] * ans[idx-1];
        }
        // Suffix //
        int suffixProduct = nums[n-1];
        ans[n-1] = ans[n-2];
        for(int idx=n-2; idx>0; idx--){
            ans[idx] = ans[idx-1] * suffixProduct;
            suffixProduct *= nums[idx];
        }
        ans[0] = suffixProduct;
        return ans;
    }
}