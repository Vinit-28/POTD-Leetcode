// Problem Link : https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description/


// Solution //
class Solution {
    public int maximumLength(String s) {
        PriorityQueue<Integer> maxLens[] = new PriorityQueue[26];
        int ans = -1;
        int n = s.length();
        
        for(int i=0; i<26; i++){
            maxLens[i] = new PriorityQueue<Integer>();
        }
        int freq = 1;
        for(int idx=1; idx<n; idx++){
            if( s.charAt(idx) != s.charAt(idx-1) ){
                char prev = s.charAt(idx-1);
                if( maxLens[prev-'a'].size() < 3 ){
                    maxLens[prev-'a'].add(freq);
                } else if( maxLens[prev-'a'].peek() < freq ){
                    maxLens[prev-'a'].poll();
                    maxLens[prev-'a'].add(freq);
                }
                freq = 0;
            }
            freq += 1;
        }
        if( maxLens[s.charAt(n-1)-'a'].size() < 3 ){
            maxLens[s.charAt(n-1)-'a'].add(freq);
        } else if( maxLens[s.charAt(n-1)-'a'].peek() < freq ){
            maxLens[s.charAt(n-1)-'a'].poll();
            maxLens[s.charAt(n-1)-'a'].add(freq);
        }
        
        for(int i=0; i<26; i++){
            if( maxLens[i].isEmpty() == false ){
                int size = maxLens[i].size();
                int top1 = maxLens[i].poll();
                int top2 = maxLens[i].isEmpty()? -1 : maxLens[i].poll();
                int top3 = maxLens[i].isEmpty()? -1 : maxLens[i].poll();
                
                // Minimum //
                ans = Math.max(ans, top1-2);
                if( size==2 ) ans = Math.max(ans, top1-1);
                if( size==3 || top1+1 <= top2 ) ans = Math.max(ans, top1);
                
                // Middle //
                ans = Math.max(ans, top2-2);
                if( top2+1 <= top3 || (top2 == top1 && top2 <= top3) ) ans = Math.max(ans, top2);
                
                // Maximum //
                ans = Math.max(ans, top3-2);
                if( top3 == top2 && top3 == top1 ) ans = Math.max(ans, top3);
                if( top3-1 <= top2 ) ans = Math.max(ans, top3-1);
            }
        }
        return ans<=0? -1 : ans;
    }
}