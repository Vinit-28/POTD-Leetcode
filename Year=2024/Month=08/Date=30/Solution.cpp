// Problem Link : https://leetcode.com/problems/modify-graph-edge-weights/description/


// Solution //
class Solution {
private:
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dest, int target) {
        vector<pair<int,int>> adj[n];
        vector<vector<int>> ans, fillable;
        // Building the initial adjacency list //
        for(auto &edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            if( w != -1 ){
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
                ans.push_back(edge);
            } else{
                fillable.push_back(edge);
            }
        }
        int currDist = dijkstra(n, adj, src, dest);
        if( currDist < target ) ans = {};
        else if( currDist == target ){
            for(auto &edge : fillable){
                edge[2] = 2e9;
                ans.push_back(edge);
            }
        } else{
            for(auto &edge : fillable){
                edge[2] = 1;
                int u = edge[0], v = edge[1], w = edge[2];
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
                ans.push_back(edge);
                currDist = dijkstra(n, adj, src, dest);
                if( currDist <= target ){
                    ans[ans.size()-1][2] += (target - currDist);
                    break;
                }
            }
            for(auto &edge : fillable){
                if( edge[2] == -1 ){
                    edge[2] = 2e9;
                    ans.push_back(edge);
                }
            }
        }
        if( currDist > target ) ans = {};
        return ans;
    }

    int dijkstra(int n, vector<pair<int,int>> adj[], int src, int dest){
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> distances(n, INT_MAX);
        pq.push({0, src});
        distances[src] = 0;
        while( pq.empty()==false ){
            auto arr = pq.top(); pq.pop();
            int currDist = arr[0], node = arr[1];
            if( node == dest ){
                return currDist;
            } else{
                // Visiting the neighbours //
                for(auto &[cn, w] : adj[node]){
                    int newDist = currDist + w;
                    if( distances[cn] > newDist ){
                        pq.push({newDist, cn});
                        distances[cn] = newDist;
                    }
                }
            }
        }
        return INT_MAX;
    }
};