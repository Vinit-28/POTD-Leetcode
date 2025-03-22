// Problem Link : https://leetcode.com/problems/count-the-number-of-complete-components/description/


// Solution //
class DSU{
private:
    vector<int> parents, componentSize, edgesCnt;
public:
    DSU(int n){
        parents = vector<int>(n, -1);
        componentSize = vector<int>(n, 1);
        edgesCnt = vector<int>(n, 0);
    }

    int findParent(int node){
        if( parents[node] == -1 ){
            return node;
        }
        return parents[node] = findParent(parents[node]);
    }

    void _union(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if( pu != pv ){
            parents[pv] = pu;
            componentSize[pu] += componentSize[pv];
            edgesCnt[pu] += 1, edgesCnt[pv] += 1;
            edgesCnt[pu] += edgesCnt[pv];
        } else{
            edgesCnt[pu] += 2;
        }
    }

    int getComponentSize(int node){
        int pnode = findParent(node);
        return componentSize[pnode];
    }

    int getEdgesCount(int node){
        int pnode = findParent(node);
        return edgesCnt[pnode];
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int count = 0;
        for(auto &edge: edges){
            dsu._union(edge[0], edge[1]);
        }
        unordered_set<int> parents;
        for(int node=0; node<n; node++){
            int pnode = dsu.findParent(node);
            if( !parents.count(pnode) ){
                parents.insert(pnode);
                int nodes = dsu.getComponentSize(pnode);
                int edgesCnt = dsu.getEdgesCount(pnode);
                if( (nodes*(nodes-1)) == edgesCnt ){
                    count += 1;
                }
            }
        }
        return count;
    }
};