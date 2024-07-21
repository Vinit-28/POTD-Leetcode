// Problem Link : https://leetcode.com/problems/build-a-matrix-with-conditions/description/


// Solution //
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        vector<vector<int>> ans(k, vector<int>(k, 0));
        vector<vector<int>> nodes(k+1, vector<int>(2, -1)); // Node position in the matrix //
        vector<int> rowOrder = getTopoOrder(k, rc);
        vector<int> colOrder = getTopoOrder(k, cc);
        // Edge Case //
        if( rowOrder.size() < k || colOrder.size() < k ){
            return {};
        }
        // Setting up the positions of nodes in the final answer matrix //
        for(int idx=0; idx<k; idx++){
            int rowNode = rowOrder[idx];
            int colNode = colOrder[idx];
            nodes[rowNode][0] = idx;
            nodes[colNode][1] = idx;
        }
        // Setting up the final answer matrix //
        for(int node=1; node<=k; node++){
            int r = nodes[node][0], c = nodes[node][1];
            ans[r][c] = node;
        }
        return ans;
    }

    vector<int> getTopoOrder(int n, vector<vector<int>> &edges){
        vector<int> adj[n+1];
        vector<int> order;
        vector<int> indegree(n+1, 0);
        queue<int> q;
        // Building the Adjacency List //
        for(auto &edge : edges){
            int u = edge[0], v = edge[1];
            indegree[v] += 1;
            adj[u].push_back(v);
        }
        // Initializing the Queue //
        for(int node=1; node<=n; node++){
            if( indegree[node] == 0 ) q.push(node);
        }
        // Topo Sort //
        while( q.empty()==false ){
            int node = q.front(); q.pop();
            order.push_back(node);
            // Visiting the neighbours //
            for(auto &cn : adj[node]){
                if( --indegree[cn] == 0 ){
                    q.push(cn);
                }
            }
        }
        return order;
    }
};