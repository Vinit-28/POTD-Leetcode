// Problem Link : https://leetcode.com/problems/find-eventual-safe-states/description/


// Solution //
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> que;
        vector<int> in(n, 0);
        vector<int> safeNodes;
        vector<bool> isSafe(n, false);
        vector<vector<int>> revGraph(n, vector<int>());
        
        for(int u=0; u<n; u++){
            for(auto &v : graph[u]){
                revGraph[v].push_back(u);
                in[u] += 1;
            }
        }
        for(int node=0; node<n; node++){
            if( in[node] == 0 ){
                que.push(node);
            }
        }
        while( que.empty()==false ){
            int size = que.size();
            while( size-- > 0 ){
                int node = que.front(); que.pop();
                isSafe[node] = true;
                for(auto &cn : revGraph[node]){
                    if( --in[cn] == 0 ){
                        que.push(cn);
                    }
                }
            }
        }
        for(int node=0; node<n; node++){
            if( isSafe[node] ){
                safeNodes.push_back(node);
            }
        }
        return safeNodes;
    }
};