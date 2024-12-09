// Problem Link : https://leetcode.com/problems/special-array-ii/description/


// Solution //
class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int n = nums.length;
        int prefix[] = new int[n];
        boolean ans[] = new boolean[queries.length];
        prefix[0] = 0;
        for(int idx=1; idx<n; idx++){
            int currParity = nums[idx]&1;
            int prevParity = nums[idx-1]&1;
            prefix[idx] = prefix[idx-1] + (currParity != prevParity? 1 : 0);
        }
        
        for(int qIdx=0; qIdx<queries.length; qIdx++){
            int l = queries[qIdx][0], r = queries[qIdx][1];
            int sum = prefix[r] - prefix[l];
            ans[qIdx] = (sum == (r-l));
        }
        return ans;
    }
}