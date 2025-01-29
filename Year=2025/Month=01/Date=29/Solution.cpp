// Problem Link : https://leetcode.com/problems/redundant-connection/description/


// Solution //
class DSU{
public:
	vector<int> parents;
	DSU(int n){
		this->parents.resize(n+1, -1);
	}

	int findParent(int node){
		if( parents[node] == -1 ){
			return node;
		}
		return parents[node] = findParent(parents[node]);
	}

	bool _union(int u, int v){
		if( isParentSame(u, v) ) return false;
		int pu = findParent(u);
		int pv = findParent(v);
		parents[pv] = pu;
		return true;
	}

	bool isBelongToSameCompo(int u, int v){
		return isParentSame(u, v);
	}

	bool isParentSame(int u, int v){
		int pu = findParent(u);
		int pv = findParent(v);
		return pu == pv;
	}
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int edgeIdxToRemove = -1;
        DSU dsu(n);

        for(int edgeIdx=0; edgeIdx<n; edgeIdx++){
            int u = edges[edgeIdx][0];
            int v = edges[edgeIdx][1];
            if( dsu.isBelongToSameCompo(u, v) ){
                edgeIdxToRemove = edgeIdx;
            }
            dsu._union(u, v);
        }
        return edges[edgeIdxToRemove];
    }
};