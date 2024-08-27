// Problem Link : https://leetcode.com/problems/path-with-maximum-probability/description/



// Solution //
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>> adj[n]; // {node:{{adjacent_node, weight}, }} //
        // Building the Adjacency List //
        for(int idx=0; idx<edges.size(); idx++){
            int u = edges[idx][0], v = edges[idx][1];
            double w = succProb[idx];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        // Dijsktra Algo //
        priority_queue<pair<double, int>> pq;
        vector<double> pathProb(n, -1.0);
        pq.push({1.0, start_node});
        pathProb[start_node] = 1.0;
        while( pq.empty()==false ){
            auto [currProb, node] = pq.top(); pq.pop();
            if( node == end_node ){
                return currProb;
            } else{
                // Exlpore the paths connecting this node to other nodes //
                for(auto &[cn, w] :adj[node]){
                    double newProb = w * currProb;
                    if( newProb > pathProb[cn] ){
                        pq.push({newProb, cn});
                        pathProb[cn] = newProb;
                    }
                }
            }
        }
        return 0.0;
    }
};