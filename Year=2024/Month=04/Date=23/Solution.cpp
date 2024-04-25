// Problem Link : https://leetcode.com/problems/minimum-height-trees/description/


// Solution //
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if( n == 1 ) return {0};
        vector<int> adj[n];
        queue<int> q;
        int indegree[n];
        vector<int> ans;
        memset(indegree, 0, sizeof(indegree));
        for(auto &edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u] += 1, indegree[v] += 1;
        }
        // Finding the root & leaf nodes -- indegree == 1 //
        for(int node=0; node<n; node++){
            if( indegree[node] == 1 ){
                q.push(node);
            }
        }
        // Removing the nodes having indegree = 1 or all the leaf nodes
        // in order to find the middle node(s).
        // There can be only 1 or 2 middle nodes //
        while( n > 2 ){
            int size = q.size();
            n -= size; // Will remove these many nodes //
            while( size-- > 0 ){
                int node = q.front(); q.pop();
                for(auto &cn : adj[node]){
                    if( --indegree[cn] == 1 ){
                        q.push(cn);
                    }
                }
            }
        }
        // Get the middle nodes //
        while( !q.empty() ){
            int node = q.front(); q.pop();
            ans.push_back(node);
        }
        return ans;
    }
};