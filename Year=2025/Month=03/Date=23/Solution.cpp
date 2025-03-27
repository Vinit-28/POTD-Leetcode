// Problem Link : https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/


// Solution //
using ll = long long;
ll MOD = 1e9+7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n, vector<pair<int,int>>());
        for(auto &road : roads){
            int u = road[0];
            int v = road[1];
            int w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
        vector<ll> cnt(n, 0);
        vector<ll> dist(n, 1e12);

        pq.push({0, 0});
        cnt[0] = 1;
        dist[0] = 0;
        while( pq.empty()==false ){
            auto v = pq.top(); pq.pop();
            ll cost = v[0], node = v[1];
            if( node == n-1 ){
                break;
            } else if( cost == dist[node] ){
                for(auto &[cn, w]: adj[node]){
                    ll newCost = cost + w;
                    if( dist[cn] >= newCost ){
                        if( dist[cn] > newCost ){
                            pq.push({newCost, cn});
                            dist[cn] = newCost;
                            cnt[cn] = 0;
                        } 
                        cnt[cn] = (cnt[cn] + cnt[node])%MOD;
                    }
                }
            }
        }
        return cnt[n-1];
    }
};