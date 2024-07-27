// Problem Link : https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/


// Solution //
class Solution {
public:
    using ll = long long;
    ll minimumCost(string s, string t, vector<char>& o, vector<char>& c, vector<int>& cost) {
        vector<vector<ll>> dist(26, vector<ll>(26, INT_MAX));
        ll ans = 0;
        for(int idx=0; idx<cost.size(); idx++){
            int u = o[idx]-'a';
            int v = c[idx]-'a';
            dist[u][v] = min(dist[u][v], ll(cost[idx]));
            dist[u][u] = dist[v][v] = 0;
        }
        floydWarshall(dist);
        for(int idx=0; idx<s.length(); idx++){
            int u = s[idx]-'a';
            int v = t[idx]-'a';
            if( dist[u][v] == INT_MAX ) return -1;
            ans += dist[u][v];
        }
        return ans;
    }   

private:
    void floydWarshall(vector<vector<ll>> &dist){
        for(int via=0; via<26; via++){
            for(int u=0; u<26; u++){
                for(int v=0; v<26; v++){
                    dist[u][v] = min(dist[u][v], dist[u][via]+dist[via][v]);
                }
            }
        }
    }
};