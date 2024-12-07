// Problem Link : https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/


// Solution //
class Solution {
    public int minimumSize(int[] nums, int maxOperations) {
        int l = 1, u = (int) 1e9;
        int ans = -1;
        while( l<=u ){
            int mid = (l+u)/2;
            if( helper(nums, maxOperations, mid) ){
                ans = mid;
                u = mid-1;
            } else{
                l = mid+1;
            }
        }
        return ans;
    }
    
    private boolean helper(int []nums, int maxOperations, int mid){
        int ops = 0;
        for(int ele: nums){
            ops += ele%mid==0? ele/mid-1 : ele/mid;
        }
        return ops <= maxOperations;
    }
}