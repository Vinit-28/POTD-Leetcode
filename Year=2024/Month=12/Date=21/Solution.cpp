// Problem Link : https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/


// Solution //
using ll = long long;
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int componentsCount = 0;
        vector<int> adj[n];
        for(auto &edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        countComponentsHavingSumDivisibleByK(adj, values, k, componentsCount, 0, -1);
        return componentsCount;
    }
    
    ll countComponentsHavingSumDivisibleByK(vector<int> adj[], vector<int> &values, int &k, int &count, int node, int parent){
        ll subtreeSum = values[node];
        for(auto &cn : adj[node]){
            if( cn != parent ){
                ll childSubtreeSum = countComponentsHavingSumDivisibleByK(adj, values, k, count, cn, node);
                subtreeSum += childSubtreeSum;
            }
        }
        if( subtreeSum % k == 0 ){
            count += 1;
            subtreeSum = 0;
        }
        return subtreeSum;
    }
};