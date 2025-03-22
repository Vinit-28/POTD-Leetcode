// Problem Link : https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/description/


// Solution //
class DSU{
private:
    vector<int> parents;
    vector<int> andVal;
public:
    DSU(int n){
        parents = vector<int>(n, -1);
        andVal = vector<int>(n, -1);
    }

    void _union(int u, int v, int w){
        int pu = findParent(u);
        int pv = findParent(v);
            parents[pv] = pu!=pv? pu : parents[pv];
            int vu = andVal[pu]==-1? w : andVal[pu];
            int vv = andVal[pv]==-1? w : andVal[pv];
            andVal[pu] = vu & vv & w;
    }

    int findParent(int node){
        if( parents[node] == -1 ){
            return node;
        }
        return parents[node] = findParent(parents[node]);
    }

    int getAndVal(int node){
        int pnode = findParent(node);
        return andVal[pnode];
    }

    bool belongToSameComp(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        return pu == pv;
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        vector<int> ans; 
        for(auto &edge: edges){
            int u = edge[0], v = edge[1], w = edge[2];
            dsu._union(u, v, w);
        }
        for(auto &q : query){
            int u = q[0], v = q[1];
            if( dsu.belongToSameComp(u, v) ){
                ans.push_back(dsu.getAndVal(u));
            } else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};