// Problem Link : https://leetcode.com/problems/valid-arrangement-of-pairs/description/


// Solution //
class Solution {
    public int[][] validArrangement(int[][] pairs) {
        HashMap<Integer, Stack<Integer>> adj = new HashMap<>();
        HashMap<Integer, Integer> in = new HashMap<>();
        HashMap<Integer, Integer> out = new HashMap<>();
        List<int[]> ans = new ArrayList<>();
        
        // Building the Adjacency List //
        for(int pair[]: pairs){
            int u = pair[0], v = pair[1];
            out.put(u, out.getOrDefault(u, 0)+1);
            in.put(v, in.getOrDefault(v, 0)+1);
            adj.computeIfAbsent(u, k -> new Stack<>()).push(v);
        }
        // Selecting the start node //
        Integer defaultStart = -1;
        Integer startNode = -1;
        for(Integer node : adj.keySet()){
            int diff = out.getOrDefault(node, 0) - in.getOrDefault(node, 0);
            if( diff == 1 ){
                startNode = node;
            }
            if( defaultStart == -1 ){
                defaultStart = node;
            }
        }
        // If no start node found, go with any node, -- defaultStart //
        if( startNode == -1 ){
            startNode = defaultStart;
        }
        DFS(startNode, adj, ans);
        Collections.reverse(ans);
        return ans.toArray(new int[ans.size()][]);
    }
    
    private void DFS(Integer node, HashMap<Integer, Stack<Integer>> adj, List<int[]> ans){
        Stack<Integer> st = adj.getOrDefault(node, new Stack<Integer>());
        while( st.isEmpty()==false ){
            Integer cn = st.pop();
            DFS(cn, adj, ans);
            ans.add(new int[]{node, cn});
        }
    }
}