// Problem Link : https://leetcode.com/problems/two-best-non-overlapping-events/description/


// Solution //
class Solution {
    public int maxTwoEvents(int[][] events) {
        int n = events.length;
        int []suffixMax = new int[n];
        int maxi = 0;
        Arrays.sort(events, new Comparator<int[]>(){
            public int compare(int []a, int []b){
                return a[0]-b[0];
            }
        });
        
        // Finding the maximum values //
        suffixMax[n-1] = events[n-1][2];
        for(int idx=n-2; idx>=0; idx--){
            suffixMax[idx] = Math.max(suffixMax[idx+1], events[idx][2]);
        }
        for(int idx=0; idx<n; idx++){
            maxi = Math.max(maxi, events[idx][2]);
            int nextIdx = getIdx(events, idx+1, events[idx][1]);
            if( nextIdx != -1 ){
                int sum = events[idx][2] + suffixMax[nextIdx];
                maxi = Math.max(maxi, sum);
            }
        }
        return maxi;
    }
    
    private int getIdx(int [][]events, int l, int start){
        int u = events.length-1;
        int idx = -1;
        while( l<=u ){
            int mid = (l+u)/2;
            if( events[mid][0] > start ){
                idx = mid;
                u = mid-1;
            } else{
                l = mid+1;
            }
        }
        return idx;
    }
}