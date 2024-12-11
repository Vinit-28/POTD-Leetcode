// Problem Link : https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/


// Solution //
class Solution {
    public int maximumBeauty(int[] nums, int k) {
        TreeMap<Integer, Integer> mpp = new TreeMap<>();
        for(int ele: nums){
            int start = ele-k;
            int end = ele+k+1;
            mpp.put(start, mpp.getOrDefault(start, 0)+1);
            mpp.put(end, mpp.getOrDefault(end, 0)-1);
        }
        int freq = 0;
        int maxFreq = 0;
        for(Map.Entry<Integer, Integer> entry : mpp.entrySet()){
            freq += entry.getValue();
            maxFreq = Math.max(freq, maxFreq);
        }
        return maxFreq;
    }
}