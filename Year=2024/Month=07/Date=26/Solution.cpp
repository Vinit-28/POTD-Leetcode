// Problem Link : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/


// Solution //
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        int minConnections = n;
        int ans = -1;
        // Adjacency Matrix or initial distance matrix //
        for(auto &edge: edges){
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = dist[v][u] = w;
            dist[u][u] = dist[v][v] = 0;
        }
        // Floyd Warshall Algo //
        for(int via=0; via<n; via++){
            for(int u=0; u<n; u++){
                for(int v=0; v<n; v++){
                    if( dist[u][via] != INT_MAX && dist[via][v] != INT_MAX ){
                        dist[u][v] = min(dist[u][v], (dist[u][via]+dist[via][v]));
                    }
                }
            }
        }
        // Finding the answer node //
        for(int u=0; u<n; u++){
            int connections = 0;
            for(int v=0; v<n; v++){
                // cout<<dist[u][v]<<" ";
                connections +=  dist[u][v] <= dt;
            }
            // cout<<endl;
            if( connections <= minConnections ){
                minConnections = connections;
                ans = u;
            }
        }
        return ans;
    }
};