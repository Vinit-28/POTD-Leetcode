// Problem Link : https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/


// Solution //
class Solution {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(new Comparator<Integer>(){
            public int compare(Integer a, Integer b){
                return b-a;
            }
        });
        long sum = 0;
        for(int gift: gifts){
            pq.offer(gift);
            sum += (long)gift;
        }
        while( k > 0 ){
            int maxi = pq.poll();
            int rt = (int)Math.sqrt(maxi);
            pq.offer(rt);
            sum -= (long)maxi;
            sum += (long)rt;11
            k -= 1;
        }
        return sum;
    }
}