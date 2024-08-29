// Problem Link : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/


// Solution //
class DSU{
public:
    vector<int> parents;
    int components;
    DSU(int n){
        parents = vector<int>(n, -1);
        components = n;
    }

    void _union(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if( pu != pv ){
            parents[pv] = pu;
            components -= 1;
        }
    }

    int findParent(int node){
        if( parents[node] == -1 ){
            return node;
        }
        return parents[node] = findParent(parents[node]);
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU dsu(n);
        map<int, vector<int>> rows, cols;
        for(int idx=0; idx<n; idx++){
            int r = stones[idx][0];
            int c = stones[idx][1];
            rows[r].push_back(idx);
            cols[c].push_back(idx);
        }
        // Making components //
        for(auto [r, arr]: rows){
            for(int i=1; i<arr.size(); i++){
                dsu._union(arr[i], arr[i-1]);
            }
        }
        // Making components //
        for(auto [c, arr]: cols){
            for(int i=1; i<arr.size(); i++){
                dsu._union(arr[i], arr[i-1]);
            }
        }
        return n - dsu.components;
    }
};
