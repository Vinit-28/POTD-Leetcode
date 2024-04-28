// Problem Link : https://leetcode.com/problems/sum-of-distances-in-tree/description/


// Solution //
class Solution {
public:
    int rootNode=0;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        int cost[n], treeSize[n];
        vector<int> ans;
        memset(cost, 0, sizeof(cost));
        memset(treeSize, 0, sizeof(treeSize));
        for(auto &edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        calculateRootNodeCost(rootNode, adj, cost, treeSize, -1, 0);
        calculateTreeCosts(rootNode, adj, cost, treeSize, -1);
        for(int node=0; node<n; node++){
            ans.push_back(cost[node]);
        }
        return ans;
    }

    int calculateRootNodeCost(int node, vector<int> adj[], int cost[], int treeSize[], int parent, int dist){
        cost[rootNode] += dist;
        int currtreeSize = 1;
        for(auto &cn : adj[node]){
            if( cn != parent ){
                int subtreeSize = calculateRootNodeCost(cn, adj, cost, treeSize, node, dist+1);
                currtreeSize += subtreeSize;
            }
        }
        return treeSize[node] = currtreeSize;
    }

    void calculateTreeCosts(int node, vector<int> adj[], int cost[], int treeSize[], int parent){
        // Finding total cost for current node //
        if( parent != -1 ){
            int parentCost = cost[parent];
            int nodesToBeVisited = (treeSize[rootNode] - treeSize[node]);
            int currNodeCost = (parentCost - treeSize[node]) + nodesToBeVisited;
            cost[node] = currNodeCost; 
        }
        // Traversing through the childs //
        for(auto &cn : adj[node]){
            if( cn != parent ){
                calculateTreeCosts(cn, adj, cost, treeSize, node);
            }
        }
    }
};
