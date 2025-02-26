// Problem Link : https://leetcode.com/problems/most-profitable-path-in-a-tree/description/


// Solution //
class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size()+1;
        vector<vector<int>> adj(n, vector<int>());
        vector<int> bobsPath(n, -1);

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        buildBobsPath(adj, bob, -1, 1, bobsPath);
        return findAlicesPath(adj, 0, -1, 1, bobsPath, amount);
    }

private:
    bool buildBobsPath(vector<vector<int>> &adj, int node, int parent, int step, vector<int> &bobsPath){
        bobsPath[node] = step;
        if( node == 0 ) return true;
        for(auto &cn : adj[node]){
            if( cn != parent && buildBobsPath(adj, cn, node, step+1, bobsPath) ) return true;
        }
        bobsPath[node] = -1;
        return false;
    }

    int findAlicesPath(vector<vector<int>> &adj, int node, int parent, int step, vector<int> &bobsPath, vector<int> &amount){
        bool isLeaf = true;
        int val = ((bobsPath[node]==-1 || bobsPath[node]>step)? amount[node] : bobsPath[node]==step? amount[node]/2 : 0);
        int maxVal = -1e9;
        for(auto &cn : adj[node]){
            if( cn != parent ){
                isLeaf = false;
                int valAhead = findAlicesPath(adj, cn, node, step+1, bobsPath, amount);
                maxVal = max(maxVal, val+valAhead);
            }
        }
        maxVal = isLeaf? max(maxVal, val) : maxVal;
        return maxVal;
    }
};