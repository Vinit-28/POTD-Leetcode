// Problem Link : https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/description/


// Solution //
class DSU{
public:
    vector<int> parents;
    DSU(int n){
        parents = vector<int>(n, -1);
    }

    int findParent(int node){
        if( parents[node]==-1 ){
            return node;
        }
        return parents[node] = findParent(parents[node]);
    }

    void _union(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if( pu != pv ){
            parents[pv] = pu;
        }
    }
};

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        DSU dsu(n+1);
        unordered_map<int, vector<int>> nodeComponents;
        vector<vector<int>> adj(n+1, vector<int>());
        int maxLevel = 0;

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            dsu._union(u, v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int node=1; node<=n; node++){
            int p = dsu.findParent(node);
            nodeComponents[p].push_back(node);
        }
        for(auto [parent, component]: nodeComponents){
            int componentMaxLevel = resolveComponent(component, adj);
            if( componentMaxLevel==-1 ) return -1;
            maxLevel += componentMaxLevel;
        }
        return maxLevel;
    }

private:

    int resolveComponent(vector<int> &component, vector<vector<int>> &adj){
        int maxi = -1;
        for(int &node : component){
            int val = BFS(node, adj);
            maxi = max(maxi, val);
        }
        return maxi;
    }

    int BFS(int src, vector<vector<int>> &adj){
        int level = 1;
        vector<int> groups(501, -1);
        queue<int> que;
        que.push(src);
        groups[src] = level;
        while( que.empty()==false ){
            int size = que.size();
            while( size-- > 0 ){
                int node = que.front(); que.pop();
                for(auto &cn : adj[node]){
                    if( groups[cn]==-1 ){
                        groups[cn] = level+1;
                        que.push(cn);
                    } else if( abs(groups[cn]-level) != 1 ){
                        return -1;
                    }
                }
            }
            level += 1;
        }
        return level-1;
    }
};