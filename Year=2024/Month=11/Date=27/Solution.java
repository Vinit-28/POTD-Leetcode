// Problem Link : https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/description/


// Solution //
class Solution {
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        int q = queries.length;
        int ans[] = new int[q];
        ArrayList<Integer> adj[] = new ArrayList[n];
        
        for(int node=0; node<n; node++){
            adj[node] = new ArrayList<Integer>();
            if( node < n-1 ) adj[node].add(node+1);
        }
        for(int i=0; i<q; i++){
            int u = queries[i][0];
            int v = queries[i][1];
            adj[u].add(v);
            ans[i] = BFS(n, adj);
        }
        return ans;
    }
    
    int BFS(int n, ArrayList<Integer> adj[]){
        boolean visited[] = new boolean[n];
        Queue<Integer> q = new LinkedList<>();
        int dist = 0;
        
        Arrays.fill(visited, false);
        q.offer(0);
        visited[0] = true;
        while( q.isEmpty()==false ){
            int size = q.size();
            while( size-- > 0 ){
                int node = q.poll();
                if( node == n-1 ){
                    return dist;
                } else{
                    for(int cn: adj[node]){
                        if( visited[cn]==false ){
                            visited[cn] = true;
                            q.offer(cn);
                        }
                    }
                }
            }
            dist += 1;
        }
        return -1;
    }
}